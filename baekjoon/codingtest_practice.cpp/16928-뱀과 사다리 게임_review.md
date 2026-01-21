## 1. 문제 분석

- **목표**: 1번 칸에서 시작하여 주사위를 굴려 100번 칸에 도착하는 **최소 횟수** 구하기.
    
- **특징**:
    - 주사위: 1~6.
        
    - 사다리를 타면 번호가 커지고, 뱀을 타면 번호가 작아짐.
        
    - **모든 이동의 가중치가 1**이므로 최단 거리를 구하는 **BFS(너비 우선 탐색)** 을 사용하여 구현함.
        

---

## 2. 시행착오 및 배운 점 (Troubleshooting)

- 1번칸에서 시작한다는걸 보지 못하고 bfs(0)을 이용하려고 했었다.
	
- 처음에는 `visited[next] > visited[curr] + 1`처럼 기존 거리와 비교하는 로직을 사용하려고 했으나.  **BFS는 먼저 방문한 경우가 무조건 최단 거리**를 보장하므로, `visited[next] == -1`(미방문) 조건 하나만으로도 충분하다는걸 배다.
    

---

## 3. 최종 코드 및 로직 설명

1. **맵 정보 저장**: `dst` 배열을 이용해 사다리와 뱀을 만나면 어디로 가야 하는지 미리 저장합니다.
    
2. **BFS 탐색**: 큐에 현재 위치를 넣고, 주사위를 굴려 나올 수 있는 6가지 경로를 탐색합니다.
    
3. **즉시 이동**: 주사위를 굴려 도착한 칸에 사다리나 뱀이 있다면 곧바로 `next` 좌표를 수정합니다.
    
4. **최단 거리 기록**: 이미 방문한 칸은 다시 가지 않도록 `visited` 배열로 체크하며 횟수를 1씩 늘려줍니다.

```c++
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 사다리와 뱀의 정보를 저장할 배열 (인덱스: 출발점, 값: 도착점)
int dst[101];
// 방문 여부와 주사위 굴린 횟수를 저장할 벡터 (-1로 초기화)
vector<int> visited(101, -1);
void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 0; // 시작 지점 굴린 횟수는 0
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        // 100번 칸에 도착하면 결과 출력 후 종료
        if (curr == 100) {
            cout << visited[100];
            return;
        }
        // 주사위 1~6 굴리기
        for (int i = 1; i <= 6; i++) {
            int next = curr + i;

            // 판을 벗어나면 무시
            if (next > 100) continue;

            // 사다리나 뱀이 있는 경우 위치 이동
            if (dst[next] != 0) {
                next = dst[next];
            }

            // 이동한 최종 위치가 처음 방문하는 곳이라면
            if (visited[next] == -1) {
                visited[next] = visited[curr] + 1;
                q.push(next);
            }
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    // 사다리(n)와 뱀(m)의 정보 입력
    for (int i = 0; i < n + m; i++) {
        int st, end;
        cin >> st >> end;
        dst[st] = end;
    }
    bfs(1); // 1번 칸에서 시작
    return 0;
}
```
