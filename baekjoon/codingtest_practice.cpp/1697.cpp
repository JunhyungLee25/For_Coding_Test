#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> location;
int visit[100001];
int bfs(int src,int dst){
    queue<int> q;
    q.push(src);
    visit[src]=1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        if(x+1==dst || x-1==dst || x<<1==dst){return visit[x];}
        if(x+1 <= 100000 && visit[x+1]==0){
            q.push(x+1);
            visit[x+1]=visit[x]+1;
        }
        if(0<=x-1 && visit[x-1]==0){
            q.push(x-1);
            visit[x-1]=visit[x]+1;
        }
        if(x<<1 <= 100000 && visit[x<<1]==0){
            q.push(x<<1);
            visit[x<<1]=visit[x]+1;
        }
    }
}
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    if(n==m){cout << 0; return 0;}
    int result = bfs(n,m);
    cout << result;
    return 0;
}

// 발전된 코드

#include <iostream>
#include <queue>
using namespace std;
int visit[100001];

void bfs(int src, int dst) {
    queue<int> q;
    q.push(src);
    visit[src] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == dst) {
            cout << visit[x] - 1 << "\n";
            return;
        }
        int next_steps[3] = {x - 1, x + 1, x * 2};
        for (int next : next_steps) {
            if (next >= 0 && next <= 100000 && visit[next] == 0) {
                visit[next] = visit[x] + 1;
                q.push(next);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    if (n == m) {cout << 0 << "\n";} 
    else {bfs(n, m);}
    return 0;
}