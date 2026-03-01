#include<iostream>
using namespace std;
int n,m,result=0;
int map[501][501];
bool visited[501][501];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
void func(int y, int x, int sum, int stage){
    if(stage==4){
        if(result < sum) result = sum;
        return ;
    }
    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if((0<=ny&&ny<n)&&(0<=nx&&nx<m)&&visited[ny][nx]==false){
            if(stage==2){
                visited[ny][nx]=true;
                func(y,x,sum+map[ny][nx],stage+1);
                visited[ny][nx]=false;
            }
            visited[ny][nx]=true;
            func(ny,nx,sum+map[ny][nx],stage+1);
            visited[ny][nx]=false;
        }
    }
}
int main(void){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    } 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j]=true;
            func(i,j,map[i][j],1);
            visited[i][j]=false;
        }
    }
    cout << result;
    return 0;
}