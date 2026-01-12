#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> graph[101];
vector<int> result_bfs;
bool visit[101];

void bfs(int temp){
    queue<int> q;
    q.push(temp);
    visit[temp]=true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        result_bfs.push_back(x);

        for(int i=0; i<graph[x].size(); i++){
            if(!visit[graph[x][i]]){
                q.push(graph[x][i]);
                visit[graph[x][i]]=true;
            }
        }
    }
}

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c,p,a,b;
    cin >> c >> p;

    for(int i=0; i<p; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(1);
    int result = result_bfs.size(); 
    cout << result-1 << '\n';
    return 0;
}