# DFS(Depth First Search)란?

- 그래프 전체를 탐색하는 방법 중 하나로 시작점 부터 다음 branch로 넘어가기 전에 해당 branch를 완벽하게 탐색하고 넘어가는 알고리즘
- **재귀함수**나 스택으로 구현한다.

# 알고리즘 동작 방식

1. 탐색 시작 노드를 스택에 삽입하고 방문처리 한다.
2. 스택의 최상단 노드에 인접한 노드중에 방문하지 않은 노드가 하나라도 있다면 그 노드를 스택에 넣고 방문처리 한다(작은 수 부터 탐색하는 규칙 설정)
3. 방문하지않은 인접 노드가 없으면 스택에 최상단에 있는 노드를 제거한다(꺼낸다).
4.  '2'의 과정을 수행할 수 없을 때까지 반복한다.
# 주의 사항

1. 노드 방문시 반드시 방문 처리를 한다.(무한 루프에 빠질 수 있음)
2. 탐색 과정이 시작 노드에서 한없이 깊어지는 것을 방지하게 위해 깊이 제한(depth bound)을 사용한다.
3. 깊이 제한에 도달할 때까지 목표노드가 발견되지 않으면 최근에 첨가된 노드의 부모노드로 돌아와(백트래킹-back tracking), 부모노드에 이전과 다른 동작자를 적용하여 새로운 자식 노드를 생성한다
## 장점

  - 단지 현 경로상의 노드만을 기억하면 되므로 저장공간의 수요가 비교적 적다.
  - 목표노드가 깊은 단계에 있을 경우 해를 빨리 구할 수 있다.

## 단점

  - 해가 없는 경로에 깊이 빠질 가능성이 있다. 따라서 실제의 경우 미리 지정한 임의의 깊이까지만 탐색하고 목표노드를 발견하지 못하면 다음 경로를 따라 탐색하는 방법이 유용할 수도 있다.
  - 얻어진 해가 최단 경로가 된다는 보장이 없다. 이는 목표에 이르는 경로가 다수인 문제에 대해 DFS는 해에 다다르면 탐색을 끝내버리므로, 이때 얻어진 해는 최적이 아닐 수도 있다.
```c
// 코드 참고 : https://github.com/ndb796/python-for-coding-test

#include <iostream>
#include <vector>
using namespace std;

// index 0은 사용하지 않음으로 배열을 하나 더 추가
bool visited[9];
vector<int> graph[9];

void dfs(int x)
{
    visited[x] = true;
    cout << x << " ";
    for (int i = 0; i < graph[x].size(); i++) // 인접한 노드 사이즈만큼 탐색
    {
        int y = graph[x][i];
        if (!visited[y]) // 방문하지 않았으면 즉 visited가 False일 때 not을 해주면 True가 되므로 아래 dfs 실행
            dfs(y); // 재귀적으로 방문
    }
}

int main(void)
{
    /* 위 그래프와 동일하게 정의 */
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);

    graph[2].push_back(1);
    graph[2].push_back(7);

    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    graph[4].push_back(3);
    graph[4].push_back(5);

    graph[5].push_back(3);
    graph[5].push_back(4);

    graph[6].push_back(7);

    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);
  
    graph[8].push_back(1);
    graph[8].push_back(7);

    dfs(1);
}
```

참고 : https://better-tomorrow.tistory.com/entry/DFS-BFS-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0 

# BFS(Breadth Frist Search)란?

- 시작 노드를 방문한 후 시작 노드에 있는 인접한 모든 노드들을 우선 방법. (최단 경로 탐색 or 임의의 경로 탐색)
- 더 이상 방문하지 않은 노드가 없을 때까지 방문하지 않은 모든 노드에 대해서도 BFS를 적용한다.
- **큐(Queue)를 이용하여 구현.**

# 알고리즘 동작 방식

1. 탐색 시작 노드를 큐에 삽입하고 방문 처리
2. 큐에서 노드를 꺼낸 뒤에 해당 노드의 인접 노드 중 방문하지 않은 노드를 모두 큐에 삽입 후 방문 처리
3. 2번 반복
- **특정 조건의 최단 경로 알고리즘**을 계산할 때 사용
## 장점
  - 출발노드에서 목표노드까지의 최단 길이 경로를 보장
## 단점

  - 경로가 매우 길 경우에는 탐색 가지가 급격히 증가함에 따라 보다 많은 기억 공간을 필요
  - 해가 존재하지 않는다면 유한 그래프의 경우, 모든 그래프를 탐색한 후에 실패로 끝난다.
  - 무한 그래프의 경우에는 결코 해를 찾지도 못하고, 끝내지도 못한다.
 ```c++
 // 코드 참고 : https://github.com/ndb796/python-for-coding-test

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visited[9];
vector<int> graph[9];

// BFS 함수 정의
void bfs(int start) {
    queue<int> q;
    q.push(start); // 첫 노드를 queue에 삽입
    visited[start] = true; // 첫 노드를 방문 처리

    // 큐가 빌 때까지 반복
    while (!q.empty()) {
        // 큐에서 하나의 원소를 뽑아 출력
        int x = q.front();
        q.pop();
        cout << x << ' ';
        
        // 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if (!visited[y]) {
                q.push(y);
                visited[y] = true; // 방문처리
            }
        }
    }
}

int main(void) {
    // 노드 1에 연결된 노드 정보 저장
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);

    // 노드 2에 연결된 노드 정보 저장
    graph[2].push_back(1);
    graph[2].push_back(7);

    // 노드 3에 연결된 노드 정보 저장
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    // 노드 4에 연결된 노드 정보 저장
    graph[4].push_back(3);
    graph[4].push_back(5);

    // 노드 5에 연결된 노드 정보 저장
    graph[5].push_back(3);
    graph[5].push_back(4);

    // 노드 6에 연결된 노드 정보 저장
    graph[6].push_back(7);

    // 노드 7에 연결된 노드 정보 저장
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    // 노드 8에 연결된 노드 정보 저장
    graph[8].push_back(1);
    graph[8].push_back(7);

    bfs(1);
}
```

