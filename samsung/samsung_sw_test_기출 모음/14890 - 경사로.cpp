#include<iostream>
using namespace std;
int N,L,cnt;
int map[101][101];
void garo(int y){
    int length=1;
    bool flag = true;
    int selected[101]={0};
    for(int i=1; i<N; i++){
        if(map[y][i-1]-map[y][i]==0){
            length++;
            continue;
        } else if(map[y][i-1]-map[y][i]!=0){ 
            if(-2>=map[y][i-1]-map[y][i]||map[y][i-1]-map[y][i]>=2){
                flag = false;
                break;
            } 
            else if(map[y][i-1]<map[y][i]){ 
                if(length<L){
                    flag = false;
                    break;
                } else if(length>=L){
                    for(int j=1; j<=L; j++){
                        if(i-j>=0 && selected[i-j]==1){
                            flag = false;
                            break;
                        }
                    }
                    if(flag==false) break;
                    length=1;
                }
            } else if(map[y][i-1]>map[y][i]){
                if(N-i<L){
                    flag = false; // 다음칸이 더 낮은 칸인데 물리적으로 L보다 길어질 수 없으면 실패
                    break;
                }
                for(int j=0; j<L; j++){
                    if(map[y][i+j]==map[y][i]) selected[i+j]=1;
                    else{
                        flag = false;
                        break;
                    }   
                } 
                length = 1;
            }
        }
    }
    if(flag) cnt++;
}
void sero(int x){
    int length=1;
    bool flag = true;
    int selected[101]={0};
    for(int i=1; i<N; i++){
        if(map[i-1][x]-map[i][x]==0){
            length++;
            continue;
        } else if(map[i-1][x]-map[i][x]!=0){ 
            if(-2>=map[i-1][x]-map[i][x]||map[i-1][x]-map[i][x]>=2){
                flag = false;
                break;
            } 
            else if(map[i-1][x]<map[i][x]){
                if(length<L){
                    flag = false;
                    break;
                } else if(length>=L){
                    for(int j=1; j<=L; j++){
                        if(i-j>=0 && selected[i-j]==1){
                            flag = false;
                            break;
                        }
                    }
                    if(flag==false) break;
                    length=1;
                }
            } else if(map[i-1][x]>map[i][x]){
                if(N-i<L){
                    flag = false; // 다음칸이 더 낮은 칸인데 물리적으로 L보다 길어질 수 없으면 실패
                    break;
                } 
                for(int j=0; j<L; j++){
                    if(map[i+j][x]==map[i][x]) selected[i+j]=1;
                    else{
                        flag = false;
                        break;
                    }   
                }
                length = 1;
            }
        }
    }
    if(flag) cnt++;
}
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> L;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<N; i++){
        garo(i);
        sero(i);
    }
    cout << cnt;
    return 0;
}