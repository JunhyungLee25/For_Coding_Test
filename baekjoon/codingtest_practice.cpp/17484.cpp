#include<iostream>
using namespace std;
int space[6][6];
int dy[3] = {1,1,1};
int dx[3] = {-1,0,1};
int n,m;
int min_val = 10000000;
void DFS(int y, int x,int dir,int tp){
    if(n==y){
        if(min_val > tp) min_val = tp;
        return;
    }
    for(int i=0; i<3; i++){
        if(dir==i) continue;
        else if(0<=x+dx[i]&&x+dx[i]<m) DFS(y+dy[i],x+dx[i],i,tp+space[y][x]);
    }
}
int main(void){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> space[i][j];
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<3; j++){
            DFS(0,i,j,0);        
        }
    }
    cout << min_val;
    return 0;
}