#include <iostream>
#include <vector>
using namespace std;
vector<int> graph[101];
vector<int> result_dfs;
bool visit[101];

void dfs(int temp){
    visit[temp]=true;
    result_dfs.push_back(temp);

    for(int i=0; i<graph[temp].size(); i++){
        if(!visit[graph[temp][i]]){
            visit[graph[temp][i]]=true;
            dfs(graph[temp][i]);
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
    dfs(1);
    int result = result_dfs.size(); 
    cout << result-1 << '\n';
    return 0;
}