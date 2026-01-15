#include<iostream>
using namespace std;
// [0][2]<->[1][6], [1][2]<->[2][6], [2][2]<->[3][6]
// [0][0] + 2*[1][0] + 4*[2][0] + 8*[3][0] 
int wheel[4][8];
void rotate(int wheel_num, int dir, int flag){
    if(flag==0){return;}
    if(dir==1){
        int temp = wheel[wheel_num][7];
        for(int i=7; i>0; i--){wheel[wheel_num][i]=wheel[wheel_num][i-1];} // 시계
        wheel[wheel_num][0]=temp;
    } else {
        int temp = wheel[wheel_num][0];
        for(int i=0; i<7; i++){wheel[wheel_num][i]=wheel[wheel_num][i+1];} // 반시계
        wheel[wheel_num][7]=temp;    
    }
}
int main(void){
    int k,wheel_num,dir;
    string n1,n2,n3,n4;
    cin >> n1 >> n2 >> n3 >> n4;
    for(int i=0; i<8; i++){
        wheel[0][i] = n1[i] - '0';
        wheel[1][i] = n2[i] - '0';
        wheel[2][i] = n3[i] - '0';
        wheel[3][i] = n4[i] - '0';
    }
    cin >> k;
    for(int i=0; i<k; i++){
        int rotate_flag[4]={0};
        int rotate_dir[4]={0};
        cin >> wheel_num >> dir;
        int cur=wheel_num-1;
        rotate_dir[cur]=dir; rotate_flag[cur]=1;
        for(int j=cur; j<3; j++){
            if(wheel[j][2]!=wheel[j+1][6]){
                rotate_dir[j+1]=-rotate_dir[j];
                rotate_flag[j+1]=1;
            } else{break;}
        }
        for(int j=cur; j>0; j--){
            if(wheel[j-1][2]!=wheel[j][6]){
                rotate_dir[j-1]=-rotate_dir[j];
                rotate_flag[j-1]=1;
            } else{break;}
        }
        for(int a=0; a<4; a++){
            rotate(a,rotate_dir[a],rotate_flag[a]);
        }
    }
    int result = wheel[0][0] + 2*wheel[1][0] + 4*wheel[2][0] + 8*wheel[3][0];
    cout << result;
    return 0;
}