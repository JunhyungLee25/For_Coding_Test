#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int dst[101];
vector<int> visited(101, -1);
void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(curr == 100){
            cout << visited[100]; return;
        }
        for(int i=1; i<=6; i++){
            int next = curr + i;
            if(next > 100) continue;
            if(dst[next]!=0){
                if(visited[dst[next]]==-1){
                    visited[dst[next]] = visited[curr] + 1;
                    q.push(dst[next]);
                }
            } else {
                if(visited[next]==-1){
                    visited[next] = visited[curr] + 1;
                    q.push(next);
                }
            }
        }
    }
}
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,st,end;
    cin >> n >> m;
    for(int i=0; i<n+m; i++){
        cin >> st >> end;
        dst[st] = end;
    }
    bfs(1);
    return 0;
}
