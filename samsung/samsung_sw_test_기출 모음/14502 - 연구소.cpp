#include<iostream>
#include<queue>
using namespace std;
int max_safe=0;
int map[8][8];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int n,m;
void VIRUS(){
    int safe_zone=0;
    int tmp_map[8][8];
    int visited[8][8]={0};
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            tmp_map[i][j] = map[i][j];
            if(map[i][j]==2) q.push(make_pair(i,j)); 
        }
    }
    while(!q.empty()){
        int tp1 = q.front().first;
        int tp2 = q.front().second;
        visited[tp1][tp2]=1;
        q.pop();
        for(int k=0; k<4; k++){
            if((0<=tp1+dy[k] && tp1+dy[k]<n) && (0<=tp2+dx[k] && tp2+dx[k]<m) && !tmp_map[tp1+dy[k]][tp2+dx[k]] && !visited[tp1+dy[k]][tp2+dx[k]]){
                tmp_map[tp1+dy[k]][tp2+dx[k]]=1;
                q.push(make_pair(tp1+dy[k],tp2+dx[k]));
                visited[tp1+dy[k]][tp2+dx[k]]=1;
            }
        }
    }    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tmp_map[i][j]==0) safe_zone++;
        }
    }
    if(max_safe<safe_zone) max_safe=safe_zone;
}
void WALL(int cnt,int start){
    if(cnt==3){
        VIRUS();
        return;
    } 
    for (int i = start; i < n * m; i++) {
        int r = i / m;
        int c = i % m; 
        if (map[r][c] == 0) {
            map[r][c] = 1;
            WALL(cnt + 1, i + 1);
            map[r][c] = 0;
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
    WALL(0,0);
    cout << max_safe;
    return 0;
}