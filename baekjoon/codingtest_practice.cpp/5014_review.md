- 문제 복기
1. 최단 거리, 횟수를 구하는 문제인데 DFS로 접근해서 오래걸렸다.
2. BFS 내부에서 방문 여부와 값이 범위를 넘는지 확인하고 큐에 넣는 부분에서, 조건을 `visited[up_F]` 먼저 적었는데 만약 `up_F`가 visited 배열의 최대 크기보다 크다면 런타임에러(out of bound)가 발생하게 된다. 조건문을 사용할 때는 이런 점도 유의깊게 보자.

- 최종 코드
```c++
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
```