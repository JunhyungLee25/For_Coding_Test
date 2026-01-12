#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> vec[10002];
vector<int> result_bfs;
vector<int> result_dfs;
bool visit[1002];

void bfs(int temp){
    queue<int> q;
    q.push(temp);
    visit[temp]=true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        result_bfs.push_back(x);

        for(int i=0; i<vec[x].size(); i++){
            if(!visit[vec[x][i]]){
                q.push(vec[x][i]);
                visit[vec[x][i]]=true;
            }
        }
    }
}
void dfs(int temp){
    result_dfs.push_back(temp);
    visit[temp]=true;

    for(int i=0; i<vec[temp].size(); i++){
        if(!visit[vec[temp][i]]){
            dfs(vec[temp][i]);
        }
    }
}
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,v,a,b;
    cin >> n >> m >> v;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        sort(vec[i].begin(),vec[i].end());
    }
    bfs(v);
    memset(visit, false, sizeof(visit));
    dfs(v);
    for(int i=0; i<result_dfs.size(); i++){
        cout << result_dfs[i] << " ";
    }
    cout << '\n';
    for(int i=0; i<result_bfs.size(); i++){
        cout << result_bfs[i] << " ";
    }
    return 0;
}