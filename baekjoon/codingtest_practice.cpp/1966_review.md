## 1. 문제 분석

이 문제는 주어진 문서들의 중요도를 확인하여, 특정 문서가 몇 번째로 인쇄되는지 알아내는 시뮬레이션 문제이다.

- **핵심 로직 (3단계)**:
    
    1. **데이터 저장**: 각 문서의 중요도와 초기 위치 정보를 `pair<int, int>` 형태로 큐에 저장한다. 동시에 중요도만을 관리하는 우선순위 큐(Max Heap)에 모든 중요도를 삽입한다.
        
    2. **우선순위 비교**: 큐의 맨 앞 문서(`front`)의 중요도가 현재 남아있는 문서 중 가장 높은 중요도(`priority_queue.top()`)인지 확인한다.
        
    3. **출력 및 재배치**:
        
        - **중요도가 가장 높다면**: 문서를 인쇄한다(`pop`). 인쇄 횟수를 1 증가시키고, 이 문서가 목표했던 위치(`m`)의 문서인지 확인한다. 맞다면 탐색을 종료한다.
            
        - **더 높은 중요도가 있다면**: 현재 문서를 꺼내어 큐의 맨 뒤로 다시 보낸다(`push`).
            

---

<br>

## 2. 배운 점

- (1) **우선순위 큐 사용**: 최대값을 즉시 찾기 위해 `priority_queue`를 사용하였다. 
    
- (2) **pair 사용**: 데이터의 위치가 계속 바뀌기 때문에 쉽게 추적할 수 있도록 `queue`에 데이터와 인덱스를 한 번에 삽입했다.
    
- (3) **반복문 조건 설정**: 데이터가 수시로 추가되고 삭제되는 시뮬레이션에서는 고정된 `for`문보다 큐의 상태를 체크하는 `while(!q.empty())`를 사용하는 것이 더 안전하고 직관적이다. 처음에 `for(int i=0; i<q.size(); i++)`을 사용했었는데 단순히 큐의 크기만큼 반복되는 것이 아니라서 잘못된 값이 나왔었다.

---

<br>

## 3. 최종 코드 및 동작 방식 정리

문서의 정보를 관리하기 위해 `queue<pair<int, int>> q`를 사용하고, 현재 인쇄 가능한 최대 중요도를 파악하기 위해 `priority_queue<int> pq`를 사용한다.

### 중요도 판단 및 인쇄 로직

매 단계마다 큐의 가장 앞에 있는 문서가 전체 대기열에서 가장 중요한지(큰지) 판단한다.

- **인쇄 조건 만족**: `q.front().first == pq.top()`인 경우, 실제 인쇄가 발생하므로 두 곳 모두에서 제거하고 카운트를 올린다.
    
- **인쇄 조건 불만족**: `q.front().first < pq.top()`인 경우, 더 중요한 문서가 뒤에 있으므로 현재 문서를 꺼내 다시 뒤로 보낸다. 이때 우선순위 큐는 건드리지 않는다.
    

```c++
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for (int i = 0; i < n; i++) {
            int importance;
            cin >> importance;
            q.push({ importance, i });
            pq.push(importance);
        }

        int cnt = 0;
        while (!q.empty()) {
            int current_val = q.front().first;
            int current_idx = q.front().second;
            q.pop();

            // 현재 문서가 가장 높은 중요도인 경우
            if (current_val == pq.top()) {
                cnt++;
                pq.pop();
                
                // 내가 찾는 문서인 경우
                if (current_idx == m) {
                    cout << cnt << "\n";
                    break;
                }
            }
            // 뒤에 더 높은 중요도가 있는 경우
            else {
                q.push({ current_val, current_idx });
            }
        }
    }
    return 0;
}
```