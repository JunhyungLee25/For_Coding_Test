#include<iostream>
#include<deque>
using namespace std;
int visit[100001];
int bfs(int src,int dst){
    deque<int> q;
    q.push_front(src);
    visit[src]=1;
    while(!q.empty()){
        int x = q.front();
        q.pop_front();
        if(x == dst){return visit[x]-1;}
        if(x!=0 && x<<1 <= 100000){
            if(visit[x<<1]==0 || visit[x<<1] > visit[x]){
                visit[x<<1]=visit[x];
                q.push_front(x<<1);
            }
        }
        if(x+1 <= 100000){
            if(visit[x+1]==0 || visit[x+1] > visit[x]+1){
                visit[x+1]=visit[x]+1;
                q.push_back(x+1);
            }
        }
        if(0<=x-1){
            if(visit[x-1]==0 || visit[x-1] > visit[x]+1){
                visit[x-1]=visit[x]+1;
                q.push_back(x-1);
            }
        }
    }
}
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    if(n==m){cout << 0;}
    else{cout << bfs(n,m);};
    return 0;
}