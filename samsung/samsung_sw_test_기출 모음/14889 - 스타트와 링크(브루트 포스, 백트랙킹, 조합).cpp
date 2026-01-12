#include<iostream>
using namespace std;
int n;
int min_result=1000000;
int team[20][20];
bool selected[20];
int min_team(){
    int start_score=0;
    int link_score=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(selected[i] && selected[j]){
                start_score += team[i][j];
            }
            if(!selected[i] && !selected[j]){
                link_score += team[i][j];
            }
        }
    }
    if(start_score > link_score){return start_score-link_score;}
    else{return link_score-start_score;}
}
void select_team(int cnt, int index){
    if(cnt == n/2){
        int min_temp = min_team();
        if(min_temp < min_result){
            min_result = min_temp;
        }
        return;
    }
    for(int i=index; i<n; i++){
        selected[i] = true;
        select_team(cnt+1,i+1);
        selected[i] = false;
    }
}
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> team[i][j];
        }
    }
    select_team(0,0);
    cout << min_result;
    return 0;
}