### 1. 문제 분석

이 문제는 $N \times N$ 격자 위에서 인접한 국가 간의 인구 차이를 이용해 연합을 형성하고, 인구를 재분배하는 과정을 반복하는 시뮬레이션 문제이다.

**핵심 로직 (3단계):**

1. **연합 탐색 (DFS):** 아직 방문하지 않은 칸을 시작점으로 상하좌우를 탐색한다. 두 나라의 인구 차이가 $L$ 이상 $R$ 이하이면 국경선을 열고 같은 연합으로 묶는다.
    
2. **인구 재분배:** 하나의 연합을 찾을 때마다 해당 연합에 속한 국가들의 인구 총합과 국가 수를 계산한다. 이후 `(인구 총합 / 국가 수)`를 연합 내 모든 칸의 새로운 인구수로 업데이트한다.
    
3. **시뮬레이션 반복 및 종료:** 더 이상 인구 이동이 일어나지 않을 때까지(모든 연합의 크기가 1일 때까지) 하루 단위로 과정을 반복하며 전체 일수를 카운트한다.
    

---

<br>

### 2. 배운 점

**(1) `std::pair`와 `std::vector` 활용법:** 좌표를 쌍으로 관리하기 위해 `vector<pair<int, int>>`를 사용하였고, `crew[k].first` 및 `crew[k].second`와 같은 접근자를 통해 벡터 내부의 구조체 데이터에 접근하는 법을 익혔다.

**(2) 전역 변수 초기화 및 타이밍:** 하루(while 루프 1회)가 지날 때마다 `visited` 배열을 초기화하고, 새로운 연합을 찾기 전 `sum`, `cnt`, `crew` 벡터를 비워주는 등 변수 관리의 중요성을 배웠다.

**(3) 시뮬레이션 종료 조건 설정:** `moved`라는 플래그 변수를 사용하여, 하루 동안 단 한 번이라도 인구 이동(연합 크기 > 1)이 발생했는지 감지하고 루프 탈출 여부를 결정하는 구조를 이해했다.

**잘못 생각한 부분:** 
- 처음에는 재귀 함수 내부에서 인구를 바로 더하고 인덱스를 넘기는 방식에서 합계 취합에 어려움을 겪었다. 하지만 시작점을 먼저 `crew`에 넣고 `visited` 처리를 한 뒤 탐색을 시작하는 방식으로 수정하여 중복 계산과 누락 문제를 해결할 수 있었다.
- 전역 변수를 함수에 넣기전에 초기화하면 데이터 오염 없이 더욱 편하게 계산 할 수 있음을 알았다.

---

<br>

### 3. 최종 코드 및 동작 방식 정리

전체 격자를 탐색하며 연합을 찾고, 연합이 형성되면 인구를 갱신하는 시뮬레이션을 수행한다.

**작동 방식:**

1. **격자 스캔:** `main` 함수의 이중 루프를 통해 `visited`가 `false`인 모든 칸에서 `find` 함수를 호출한다.
    
2. **연합 수집:** `find` 함수(DFS)는 국경선 개방 조건을 만족하는 인접 국가들을 `crew` 벡터에 모두 담고 인구 합계(`sum`)와 국가 수(`cnt`)를 누적한다.
    
3. **데이터 갱신:** 탐색이 끝난 후 `crew.size()`가 2 이상이면 실제로 인구 이동이 일어난 것이므로 `avg` 값을 계산해 `map`을 갱신하고 `moved`를 `true`로 바꾼다.
    
4. **일수 증가:** 모든 칸에 대한 확인이 끝난 후 `moved`가 `true`라면 `day`를 1 증가시키고 다시 다음 날의 탐색을 시작한다.
    

```c++
#include<iostream>
#include<vector>
#include<cmath> // abs() 함수 사용을 위해 포함
using namespace std;

int N, L, R;
int day, sum, cnt;
int map[51][51];
bool visited[51][51];
vector<pair<int, int>> crew; // 연합에 속한 국가들의 좌표를 저장하는 벡터
int dy[4] = {-1, 0, 1, 0};   // 상하좌우 탐색을 위한 방향 벡터
int dx[4] = {0, 1, 0, -1};

// DFS를 통해 연합을 찾는 함수
void find(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        // 1. 격자 범위 확인 및 방문 여부 확인
        if ((0 <= ny && ny < N) && (0 <= nx && nx < N) && !visited[ny][nx]) {
            // 2. 인접한 나라와의 인구 차이 계산
            int diff = abs(map[ny][nx] - map[y][x]);
            
            // 3. 인구 차이가 조건(L~R)에 부합하면 연합 추가
            if (diff >= L && diff <= R) {
                visited[ny][nx] = true;         // 방문 처리
                crew.push_back({ny, nx});       // 연합 리스트에 추가
                sum += map[ny][nx];             // 연합 총 인구수 누적
                cnt++;                          // 연합 국가 수 증가
                find(ny, nx);                   // 재귀적으로 다음 칸 탐색
            }
        }
    }
}

int main(void) {
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    // 더 이상 인구 이동이 없을 때까지 무한 반복
    while (true) {
        bool moved = false; // 오늘 인구 이동이 있었는지 체크

        // 1. 매일 아침 방문 기록 초기화
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                visited[i][j] = false;
            }
        }

        // 2. 격자의 모든 칸을 돌며 새로운 연합 탐색
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    // 연합 정보 초기화 및 시작점 추가
                    crew.clear();
                    crew.push_back({i, j});
                    sum = map[i][j];
                    cnt = 1;
                    visited[i][j] = true;

                    find(i, j); // DFS 시작

                    // 3. 연합이 형성되었다면 (국가 수가 2개 이상이면)
                    if (crew.size() > 1) {
                        moved = true;      // 인구 이동 발생 표시
                        int avg = sum / cnt; // 평균 인구 계산
                        
                        // 연합 내 모든 국가의 인구 갱신
                        for (int k = 0; k < crew.size(); k++) {
                            map[crew[k].first][crew[k].second] = avg;
                        }
                    }
                }
            }
        }

        // 4. 하루 동안 아무런 인구 이동이 없었다면 종료
        if (!moved) break;
        day++; // 인구 이동이 있었다면 하루 증가
    }

    cout << day; // 최종 인구 이동 일수 출력
    return 0;
}
```