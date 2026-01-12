#include<iostream>
#include<vector>
using namespace std;
struct con{
    int dur;
    int robo;
};
int main(void){
    int n,k;
    cin >> n >> k;
    int step=0;
    vector<con> belt(2*n);
    for(int i=0; i<n*2; i++){cin >> belt[i].dur;} // durability
    while(1){
        step++;
        // step 1
        int dur_temp = belt[n*2-1].dur;
        for(int i=n*2-2; i>=0; i--){belt[i+1].dur=belt[i].dur;}
        for(int i=n-2; i>=0; i--){belt[i+1].robo=belt[i].robo; belt[i].robo=0;}
        belt[0].dur = dur_temp;

        // step 2
        if(belt[n-1].robo==1){belt[n-1].robo=0;}
        for(int i=n-2; i>=0; i--){
            if(belt[i+1].dur>=1 && belt[i+1].robo==0 && belt[i].robo!=0){
                belt[i+1].robo=1;
                belt[i+1].dur--;
                belt[i].robo=0;
                if(belt[i+1].dur==0){k--;}
            }
        }
        // step 3
        if(belt[0].dur>0){
            belt[0].robo=1;
            belt[0].dur--;
            if(belt[0].dur==0){k--;}
        }
        // step 4
        if(k<=0){break;}
    }
    cout << step;
    return 0;
}