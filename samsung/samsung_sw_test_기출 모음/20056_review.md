## 1. 문제 분석

- **목표**: $N \times N$ 격자에서 $K$번의 이동 후 남아있는 파이어볼의 총 질량 합 구하기.
    
- **핵심 조건**:
    
    1. **이동**: 모든 파이어볼이 자신의 방향($d$)과 속력($s$)으로 이동. 
	    - 1번과 $N$번 행/열은 연결되어 있음
        
    2. **합체 및 분열**: 이동 후 한 칸에 2개 이상의 파이어볼이 있으면 하나로 합쳐진 뒤 4개로 분열됨.
        
        - 질량: $\lfloor(\text{질량 합} / 5)\rfloor$
            
        - 속력: $\lfloor(\text{속력 합} / \text{합쳐진 개수})\rfloor$
            
        - 방향: 합쳐지는 파이어볼의 방향이 모두 홀수이거나 모두 짝수면 (`0, 2, 4, 6`), 그렇지 않으면 (`1, 3, 5, 7`).
            
    3. **소멸**: 질량이 0인 파이어볼은 사라짐.
        

---
## 2. 배운점

### 구조체 Vector 배열을 이용한 그룹화

특정 좌표에 어떤 객체들이 모여있는지 관리할 때 `vector<int> map[51][51]` 방식을 사용하였다. vector이므로 `puch_back`을 이용해 동일 좌표에 파이어볼을 겹치게 넣을 수 있다.

- **장점**: `map[r][c].size()`로 해당 칸의 객체 개수를 즉시 파악 가능하고, 인덱스를 저장함으로써 원본 데이터(`fb`)에 빠르게 접근할 수 있음.
    

### 순환 격자(Circular Grid) 좌표 계산

격자의 끝과 끝이 연결된 경우, 나머지 연산(`%`)을 활용한 계산법을 알게 되었다.

- **공식**: `(현재좌표 + (이동방향 * 이동거리 % N) + N) % N`
    
- **이유**: 음수 좌표가 나오는 것을 방지하기 위해 `+N`을 해준 뒤 다시 `%N`을 취함.
    

---

## 3. 최종 코드 및 동작 방식

### 핵심 로직 (Main Loop)

1. **Step 1: 이동**: 현재 파이어볼 리스트를 순회하며 새 위치(`ny, nx`)를 계산하고, `map[ny][nx]`에 해당 파이어볼의 번호를 넣습니다.
    
2. **Step 2: 처리**: 전 격자를 검사하며 파이어볼이 1개인 곳은 그대로 유지, 2개 이상인 곳은 질량/속도/방향 로직에 따라 분열시켜 `nx_fb`에 담습니다.
    
3. **Step 3: 갱신**: 다음 턴을 위해 `fb = nx_fb`를 통해 파이어볼 리스트를 최신화합니다.
    

### 최종 코드

```c++
#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct fireball { int y, x, m, s, d; };

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    vector<fireball> fb;
    for (int i = 0; i < m; i++) {
        int y, x, m_v, s_v, d_v;
        cin >> y >> x >> m_v >> s_v >> d_v;
        fb.push_back({y - 1, x - 1, m_v, s_v, d_v});
    }

    while (k--) {
        vector<int> map[51][51];
        for (int j = 0; j < fb.size(); j++) {
            int ny = ((fb[j].y + (dy[fb[j].d] * (fb[j].s % n))) + n) % n;
            int nx = ((fb[j].x + (dx[fb[j].d] * (fb[j].s % n))) + n) % n;
            map[ny][nx].push_back(j);
        }

        vector<fireball> nx_fb;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (map[r][c].empty()) continue;
                if (map[r][c].size() == 1) {
                    fireball curr = fb[map[r][c][0]];
                    nx_fb.push_back({r, c, curr.m, curr.s, curr.d});
                } else {
                    int m_val = 0, s_val = 0, d_cnt = 0, cnt = map[r][c].size();
                    for (int idx : map[r][c]) {
                        m_val += fb[idx].m; s_val += fb[idx].s;
                        if (fb[idx].d % 2 == 0) d_cnt++;
                    }
                    int m_res = m_val / 5, s_res = s_val / cnt;
                    if (m_res == 0) continue;
                    bool same = (d_cnt == cnt || d_cnt == 0);
                    for (int dir = 0; dir < 4; dir++) 
                        nx_fb.push_back({r, c, m_res, s_res, same ? dir * 2 : dir * 2 + 1});
                }
            }
        }
        fb = nx_fb;
    }

    int total_m = 0;
    for (auto& f : fb) total_m += f.m;
    cout << total_m;
    return 0;
```