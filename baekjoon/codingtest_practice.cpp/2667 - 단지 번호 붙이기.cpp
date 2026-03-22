#include<iostream>
#include<queue>
using namespace std;
int N,tot,cnt=0;
int map[26][26];
bool visited[26][26];
priority_queue<int, vector<int>, greater<int>> minPq;
// 위,오,아,왼
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

void DFS(int r, int c){
    if(map[r][c]==0){
        return;
    }
    cnt++;
    visited[r][c] = true;
    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
        if(visited[nr][nc] == 0 && map[nr][nc]==1){
            DFS(nr, nc);
        } 
    }
}
int main(void){
    string S[26];
    cin >> N;
    // input
    for(int i=0; i<N; i++){
            cin >> S[i];
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            map[i][j] = S[i][j] - '0';
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j]==1 && visited[i][j] == 0){
                cnt = 0;
                DFS(i,j);
                minPq.push(cnt);
                tot++;
            }
        }
    }
    cout << tot << '\n';
    while(!minPq.empty()){
        cout << minPq.top() << '\n';    
        minPq.pop();
    }

    return 0;
}