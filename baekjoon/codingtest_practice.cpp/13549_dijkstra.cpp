#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int INF = 1e9;
int dist[100001];
int dijkstra(int src, int dst){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;// 최소시간, 현재위치 (오름차순)
    for(int i=0; i<100001; i++){dist[i]=INF;}
    dist[src]=0; pq.push({0,src});

    while(!pq.empty()){
        int time = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if(time > dist[curr]){continue;}
        if(curr == dst){return time;}
        if(curr!=0 && curr*2 <= 100000){
            if(dist[curr*2] > time){
                dist[curr*2]=time;
                pq.push({time,curr*2});
            }
        }
        if(curr+1 <= 100000){
            if(dist[curr+1] > time+1){
                dist[curr+1]=time+1;
                pq.push({time+1,curr+1});
            }
        }
        if(curr-1 >= 0){
            if(dist[curr-1] > time+1){
                dist[curr-1]=time+1;
                pq.push({time+1,curr-1});
            }
        }
    }
}
int main(void){
    int n,m;
    cin >> n >> m;
    if(n==m){cout << 0;}
    else{cout << dijkstra(n,m);}
    return 0;
}
