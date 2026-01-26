## 1. 문제 분석

정해진 총예산 내에서 여러 지방의 예산 요청을 최대한 배정하는 문제이다.

- **조건 1:** 모든 요청을 다 들어줄 수 있으면 그대로 배정한다.
    
- **조건 2:** 총합이 예산을 초과하면 특정 **상한액(Limit)**을 정해 그보다 큰 요청은 상한액만큼만 주고, 작은 요청은 그대로 준다.
    
- **목표:** 예산 총액을 넘지 않으면서 **상한액을 최대화**하는 값을 찾아야 한다.
    

---
## 2. 배운 점

- [이분탐색](/algorithm/이분탐색.md) 사용법.

****
## 3. 최종 코드 및 동작 방식

### 동작 방식 설명

1. **초기 판단:** 모든 예산의 합(`total`)이 가용 예산(`m`) 이하면 가장 큰 요청액을 출력한다.
    
2. **범위 설정:** 상한액이 될 수 있는 최소치(`0`)와 최대치(`max_val`)를 `low`와 `high`로 잡는다.
    
3. **이분 탐색 수행:**
    
    - 중간값(`mid`)을 상한액이라고 **가정**한다.
        
    - `for`문을 돌며 모든 지역에 `min(요청액, mid)`만큼 돈을 줬을 때의 총합(`cur_total`)을 계산한다.
        
4. **조건 판별:**
    
    - **합이 예산 이내라면:**  low = mid + 1
        
    - **합이 예산을 초과하면:** high = mid - 1
        
5. **최종 출력:** `low > high`가 되어 탐색이 끝나면, 가장 마지막으로 조건을 만족했던 `limit`을 출력한다다.

```c++
#include<iostream>
#include<algorithm>

using namespace std;

// 내림차순 정렬을 위한 비교 함수 (사실 이분 탐색만 한다면 생략 가능합니다)
bool compare(int a, int b) { return a > b; }

int main(void) {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;
    int money[10001];
    int total = 0;
    int max_val = 0;

    for (int i = 0; i < n; i++) {
        cin >> money[i];
        total += money[i];
        if (max_val < money[i]) { max_val = money[i]; }
    }
    cin >> m;

    // 모든 요청을 들어줄 수 있는 경우
    if (m - total >= 0) {
        cout << max_val;
    } 
    // 예산이 부족하여 상한액을 찾아야 하는 경우
    else {
        int low = 0;
        int high = max_val;
        int limit = 0;

        while (low <= high) {
            int mid = (low + high) / 2; // 현재 가정하는 상한액
            long long cur_total = 0;

            for (int i = 0; i < n; i++) {
                // 요청액과 상한액 중 작은 값을 배정
                cur_total += min(money[i], mid);
            }

            if (cur_total <= m) {
                // 예산 내에 들어오면, 일단 정답으로 저장하고 더 큰 상한액을 탐색
                limit = mid;
                low = mid + 1;
            } else {
                // 예산을 초과하면, 상한액을 줄여야 함
                high = mid - 1;
            }
        }
        cout << limit;
    }
    return 0;
}
```