## 1. 문제 분석

이 문제는 사무실의 격자 정보와 CCTV 위치가 주어졌을 때, CCTV의 방향을 적절히 설정하여 사각지대의 크기를 최소화하는 시뮬레이션 및 완전 탐색 문제이다.

- **핵심 로직 (3단계)**:
    
    1. **CCTV 정보 수집**: 입력 단계에서 벽이 아닌 CCTV(1~5번)의 좌표와 타입을 별도의 리스트(`cctv_list`)에 저장한다.
        
    2. **백트래킹을 통한 완전 탐색**: 재귀 함수를 사용하여 각 CCTV가 가질 수 있는 모든 방향 조합($O(4^K)$)을 탐색한다. 여기서 $K$는 CCTV의 개수이며 최대 8개이다.
        
    3. **지도 복사 및 시뮬레이션**: 각 방향 결정 시 현재 지도를 복사(`cpMap`)하여 독립적인 감시 영역을 표시(`ob`)하고, 모든 CCTV의 설정이 끝나면 사각지대를 계산(`find`)한다.
        

---

<br>

## 2. 배운 점

- (1) **상태 보존과 복구**: 백트래킹 탐색 시 전역 배열을 직접 수정하면 다른 탐색 경로에 영향을 주므로, 매 단계마다 현재 상태의 복사본(`cp_map`)을 만들어 다음 재귀로 넘겨주는 방식의 중요성을 학습하였다.
    
- (2) **제어 흐름 최적화**: CCTV 5번과 같이 회전이 의미 없는 경우나 2번처럼 대칭적인 방향을 가진 경우, `break` 문을 적절히 사용하여 불필요한 재귀 호출을 방지하고 연산 효율을 높였다.
    
- (3) **모듈화의 이점**: 직선 방향 감시(`ob`), 사각지대 계산(`find`), 지도 복사(`cpMap`) 등 반복되는 로직을 함수로 분리하여 코드의 가독성을 높이고 디버깅을 용이하게 하였다.
    

---

<br>

## 3. 최종 코드 및 동작 방식 정리

모든 CCTV의 방향을 결정하는 `bt` 함수를 호출하며, 각 단계에서 CCTV 타입에 맞는 방향들을 `ob` 함수를 통해 감시 구역(`7`)으로 마킹한다.

### 데이터 구조

- `struct CCTV`: CCTV의 y, x 좌표와 타입을 관리한다.
    
- `int map[8][8]`: 원본 사무실 정보를 저장한다.
    
- `vector<CCTV> cctv_list`: 사무실 내 모든 CCTV 객체를 저장한다.
    

### 시뮬레이션 로직

- `ob` 함수는 벽(`6`)을 만나거나 경계를 벗어날 때까지 지정된 방향으로 전진하며 빈칸(`0`)을 감시 구역(`7`)으로 바꾼다.
    

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[8][8];
int dy[4] = {-1, 0, 1, 0}; // 북, 동, 남, 서
int dx[4] = {0, 1, 0, -1};
int n, m;
struct CCTV {
    int y, x, type;
};
vector<CCTV> cctv_list;
int ans = 10000000;

// 사각지대 개수 계산 및 최솟값 갱신
void find(int tp[8][8]) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tp[i][j] == 0) result++;
        }
    }
    ans = min(ans, result);
}

// 특정 방향으로 감시 영역 표시
void ob(int y, int x, int dir, int tp[8][8]) {
    while (1) {
        y += dy[dir];
        x += dx[dir];
        if (y >= 0 && y < n && x >= 0 && x < m) {
            if (tp[y][x] == 6) break; // 벽을 만나면 중단
            if (tp[y][x] == 0) tp[y][x] = 7; // 빈칸만 감시 구역으로 표시
        } else break; // 경계를 벗어나면 중단
    }
}

// 지도 복사 함수
void cpMap(int dest[8][8], int src[8][8]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dest[i][j] = src[i][j];
        }
    }
}

// 백트래킹 탐색 함수
void bt(int idx, int cm[8][8]) {
    if (idx == cctv_list.size()) {
        find(cm);
        return;
    }

    int ctype = cctv_list[idx].type;
    int cy = cctv_list[idx].y;
    int cx = cctv_list[idx].x;

    for (int dir = 0; dir < 4; dir++) {
        int cp_map[8][8];
        cpMap(cp_map, cm);

        if (ctype == 1) {
            ob(cy, cx, dir, cp_map);
        } else if (ctype == 2) {
            if (dir >= 2) break; // 가로, 세로 두 가지 방향만 확인
            ob(cy, cx, dir, cp_map);
            ob(cy, cx, dir + 2, cp_map);
        } else if (ctype == 3) {
            ob(cy, cx, dir, cp_map);
            ob(cy, cx, (dir + 1) % 4, cp_map);
        } else if (ctype == 4) {
            ob(cy, cx, dir, cp_map);
            ob(cy, cx, (dir + 1) % 4, cp_map);
            ob(cy, cx, (dir + 2) % 4, cp_map);
        } else if (ctype == 5) {
            ob(cy, cx, 0, cp_map);
            ob(cy, cx, 1, cp_map);
            ob(cy, cx, 2, cp_map);
            ob(cy, cx, 3, cp_map);
            bt(idx + 1, cp_map); // 5번은 회전이 무의미하므로 한 번만 재귀 호출 후 종료
            break;
        }
        bt(idx + 1, cp_map);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (1 <= map[i][j] && map[i][j] <= 5) {
                cctv_list.push_back({i, j, map[i][j]});
            }
        }
    }

    bt(0, map);
    cout << ans;
    return 0;
}
```