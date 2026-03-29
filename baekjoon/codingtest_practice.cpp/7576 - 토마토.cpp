#include<iostream>
#include<queue>
using namespace std;
#define MAX 1001
int N,M;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int map[MAX][MAX];
queue<pair<int,int>> q;

void BFS(){
    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int dir=0; dir<4; dir++){
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if(ny<0||nx<0||ny>=N||nx>=M) continue;
            if(map[ny][nx]==0 || map[ny][nx]>map[cy][cx]+1){
                map[ny][nx]=map[cy][cx]+1;
                q.push({ny,nx});
            }
        }
    }
}

int main(void){
    cin >> M >> N;
    int day=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]==1){
                q.push({i,j});
            }
        }
    }
    BFS();
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(day<map[i][j]){
                day = map[i][j];
            } else if(map[i][j]==0){
                cout << -1;
                return 0;
            }
        }
    }
    cout << day-1;
    return 0;
}