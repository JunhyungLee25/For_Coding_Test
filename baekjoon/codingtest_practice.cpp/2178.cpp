#include <iostream>
#include <queue>
using namespace std;
#define max 101
int graph[max][max];
int route[max][max];
bool visit[max][max];
int n,m;
int x_dir[4] = {-1,1,0,0};
int y_dir[4] = {0,0,-1,1};

void bfs(int start_x, int start_y){
    queue<pair<int,int>> q;
    visit[start_x][start_y]=true;
    q.push(make_pair(start_x,start_y));
    route[start_x][start_y]=1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int go_x = x + x_dir[i];
            int go_y = y + y_dir[i];

            if((0<=go_x && go_x<n) && (0<=go_y && go_y<m) && visit[go_x][go_y]==0 && graph[go_x][go_y]==1){
                visit[go_x][go_y]=true;
                q.push(make_pair(go_x,go_y));
                route[go_x][go_y] = route[x][y]+1;
            }
        }
    }
}

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        string row;
        cin >> row;
        for(int j=0; j<m; j++){
            graph[i][j] = row[j]-'0';
        }
    }
    bfs(0,0);
    cout << route[n-1][m-1] << '\n';
    return 0;
}