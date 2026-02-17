## 1. 문제 분석

이 문제는 여러 팀이 참여한 대회에서 특정 팀의 순위를 계산하는 시뮬레이션 문제이다. 단순히 점수만 비교하는 것이 아니라 여러 단계의 동점자 처리 규정을 정확히 구현해야 한다.

- **핵심 로직 (3단계)**:
    
    1. **데이터 수집 및 갱신**: 각 로그를 읽으며 팀별 문제 최고 점수, 총점, 제출 횟수, 마지막 제출 시간을 실시간으로 업데이트한다.
        
    2. **점수 갱신 최적화**: 새로운 점수가 기존 최고점보다 높을 때만 총점에 그 차이만큼(`s - score[ti][pi]`)을 더해 중복 계산을 방지한다.
        
    3. **순위 산정 (우선순위 규정)**:
        
        - 총점이 높은 팀이 더 높은 순위를 가진다.
            
        - 총점이 같으면 제출 횟수가 적은 팀이 더 높은 순위를 가진다.
            
        - 제출 횟수까지 같으면 마지막 제출 시간이 빠른 팀이 더 높은 순위를 가진다.
            

---

<br>

## 2. 배운 점

- (1) **차분 업데이트**: 총점을 매번 처음부터 다시 계산하지 않고, 기존 점수와의 차이만큼만 더해주는 방식을 통해 연산 횟수를 줄이는 법을 사용하여 `if-else`문을 사용하지 않고 간략하게 구현하였다..
    
- (2) **상태 기록을 통한 시간 복잡도 개선**: 순위를 비교할 때마다 전체 로그를 다시 뒤지는 for-loop방식을 사용했었다가 각 팀 번호를 인덱스로 하여 각 팀의 마지막 시간을 저장하도록 하였다.
- `last_time[ti]=i` , `if(last_time[i] < last_time[mt])` -> 마지막에 loop를 돌며 찾는 것이 아닌 비교해야될 두 팀의 마지막 제출 시간만 빠르게 비교가 가능했다.
    
- (3) **배열 인덱스 설계**: 2차원 배열의 0번 인덱스 공간을 총점 저장용으로 활용하여 데이터 구조를 단순화하고 접근성을 높였다.
    

---

<br>

## 3. 최종 코드 및 동작 방식 정리

팀 정보를 저장하기 위해 `score`, `count`, `last_time` 배열을 사용한다. 모든 로그를 처리한 후, 내 팀(`mt`)과 나머지 팀들을 순차적으로 비교하며 나보다 성적이 좋은 팀의 숫자를 세어 최종 순위를 결정한다.

### 데이터 구조

- `score[team_id][prob_id]`: 특정 팀의 문제별 최고 점수.
    
- `score[team_id][0]`: 특정 팀의 획득 총점.
    
- `count[team_id]`: 특정 팀의 전체 제출 횟수.
    
- `last_time[team_id]`: 특정 팀의 마지막 제출 시점.
    

### 순위 비교 로직

타 팀 `i`가 내 팀 `mt`보다 순위가 높은 조건은 다음과 같다.

1. `score[i][0] > score[mt][0]`
    
2. `score[i][0] == score[mt][0]` 이면서 `count[i] < count[mt]`
    
3. 위의 두 조건이 모두 같으면서 `last_time[i] < last_time[mt]`
    

```c++
#include<iostream>
using namespace std;

int main(void){
    // 입출력 성능 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n, k, mt, m;
        int ti, pi, s;
        cin >> n >> k >> mt >> m;

        // 데이터 저장용 배열 (범위 주의: 문제 조건에 따라 크기 조절 필요)
        int score[101][101] = {0};
        int count[101] = {0};
        int last_time[101] = {0};

        for(int i = 0; i < m; i++){
            cin >> ti >> pi >> s;
            // 1. 최고 점수 및 총점 갱신
            if(score[ti][pi] < s){
                score[ti][0] += (s - score[ti][pi]); // 기존 점수와의 차이만큼 합산
                score[ti][pi] = s;
            }
            // 2. 제출 횟수 누적
            count[ti]++;
            // 3. 마지막 제출 시점 기록
            last_time[ti] = i;
        }

        int ms = score[mt][0]; // 내 팀 점수
        int mr = 1; // 내 순위 (1위부터 시작)

        for(int i = 1; i <= n; i++){
            if(mt == i) continue;

            // 우선순위에 따른 비교 (총점 > 제출 횟수 > 제출 시간)
            if(score[i][0] > ms) {
                mr++;
            } else if(score[i][0] == ms) {
                if(count[i] < count[mt]) {
                    mr++;
                } else if(count[i] == count[mt]) {
                    if(last_time[i] < last_time[mt]) {
                        mr++;
                    }
                }
            }
        }
        cout << mr << '\n';
    }
    return 0;
}
```