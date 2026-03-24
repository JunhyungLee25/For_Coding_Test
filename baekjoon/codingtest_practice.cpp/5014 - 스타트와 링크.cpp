#include<iostream>
#include<queue>
using namespace std;

int F,S,G,U,D;
bool visited[1000001];

int BFS(int cnt){
    queue<pair<int,int>> q;
    q.push({S,cnt});
    visited[S]=1;

    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();
        if(curr.first==G) return curr.second;
        int up_F = curr.first + U;
        int dn_F = curr.first - D;
        if(up_F<=F && visited[up_F]==0){
            visited[up_F]=1;
            q.push({up_F,curr.second+1});
        }
        if(dn_F>=1 && visited[dn_F]==0){
            visited[dn_F]=1;
            q.push({dn_F,curr.second+1});
        }
    }
    return -1;
}

int main(void){
    cin >> F >> S >> G >> U >> D;
    if(S==G){
        cout << 0;
        return 0;
    } 
    int result = BFS(0);
    if(result == -1) cout << "use the stairs";
    else if(result) cout << result;
    return 0;
}