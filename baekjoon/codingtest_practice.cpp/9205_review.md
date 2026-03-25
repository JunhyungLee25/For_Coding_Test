- 문제 복기
1. x,y의 범위가 너무 크기 때문에 주어진 위치를 모두 담을 수 있는 배열을 만들 수 없다. 따라서, vector를 사용하여 주어진 좌표를 index로 관리한다.
2. vector 초기화를 안해서 문제가 생겼다.

- 동작 방식
1. 주어진 좌표를 모두 store vector에 담는다.
2. 출발지점에 방문 표시를 하고 큐에 담는다.
3. 큐에 담긴 출발지점을 기준으로 모든 좌표(i~i+1)까지의 거리를 계산하여 1000m 이하(맥주 20개 최대거리)인지 확인한다.
4. 1000m이하이면 큐에 담고 방문처리 한다.
5. 3~4를 반복하다가 n+1에 도달하면 flag를 toggle하고 break.
6. flag가 참이면 'happy' 아니라면 'sad'를 출력한다.

- 최종코드 (제미나이의 힘을 빌려 더 깔끔하게 만든 버전)
  큐가 원래 pair로 구현했는데 단순히 index로만 접근하도록 수정함.
```c++
#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;

int t,n,y,x;

int main(void){
    cin >> t;
    while(t--){
        bool flag = false;
        cin >> n;
        queue<int> q;
        vector<pair<int, int>> store;
        vector<bool> visited(n+2, false);
        
        for(int i=0; i<n+2; i++){
            cin >> y >> x;
            store.push_back({y,x});
        }

        q.push(0);
        visited[0] = true;
    
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(curr == n+1){
                flag = true;
                break;
            }
            for(int i=1; i<n+2; i++){
                if(!visited[i]){
                    int dist = abs(store[curr].first - store[i].first) + abs(store[curr].second -  store[i].second);
                    if(dist<=1000){
                        visited[i]=true;
                        q.push(i);
                    }
                }
            }        
        }
        if(flag) cout << "happy" << '\n';
        else cout << "sad" << '\n'; 
    }
    return 0;
}

```