## 로봇 청소기 문제 풀이 및 분석

### 1. 실수가 있었던 부분 

- **좌표 변환 ($x, y$)의 혼동**:
    
    - 수학적 좌표계에서는 $(x, y)$ 순서로 표현하지만, 2차원 배열에서는 `room[row][col]` 즉, `room[y][x]` 순서로 접근해야 하는데 문제 푸는 와중에 이를 고려하지 않고 혼합해서 생각하여 코드가 꼬였다.
        
    - `dy`, `dx` 배열을 설정할 때 **북(0), 동(1), 남(2), 서(3)** 순서에 맞춰 인덱스를 정확히 매칭하는 것이 핵심인 문제였다.
        
- **문제 조건의 엄격한 준수**:
    
    - 문제에서 주어진 순서대로 구현해야 하는데 이를 깊게 고려하지 않고 구현해서 실수가 많이 나온 것 같다.  

---

### 3. 코드 동작 방식 상세 설명

#### 상태 정의: 0(청소되지 않음), 1(벽), 2(청소 완료).
#### 방향 및 좌표 설정
```c++
int dy[4] = {-1, 0, 1, 0}; // 북, 동, 남, 서 (행 이동)
int dx[4] = {0, 1, 0, -1}; // 북, 동, 남, 서 (열 이동)
```

#### 주변 빈칸 탐색 및 회전 (Mod 연산 활용)

- **반시계 회전**: `dir = (dir + 3) % 4;`
    
    - 현재 방향에서 왼쪽으로 도는 동작을 나머지 연산자로 간결하게 표현하였다.
	      
- **후진**: `int counter = (dir + 2) % 4;`
    
    - 바라보는 방향의 정반대 방향 인덱스를 계산하여 후진 위치를 찾는다

#### 작동 중지 조건

- 주변에 청소할 곳이 없고, 뒤쪽마저 벽(`room[ny][nx] == 1`)인 경우 `break`를 통해 루프를 탈출한다.
    

---

### 4. 최종 구현 코드 (C++)
```c++
#include <iostream>
using namespace std;

int room[50][50];
// 북(0), 동(1), 남(2), 서(3) 순서에 따른 y, x 이동량
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int result = 0;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x, y, dir;
    cin >> n >> m;
    cin >> y >> x >> dir; // 주의: 문제에 따라 y(r), x(c) 순서로 입력됨

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }

    while (true) {
        // 1. 현재 위치 청소
        if (room[y][x] == 0) {
            room[y][x] = 2; 
            result++;
        }

        // 2. 주변 4칸 중 청소되지 않은 빈칸이 있는지 확인
        bool found = false;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (room[ny][nx] == 0) {
                found = true;
                break;
            }
        }

        if (!found) {
            // 3. 청소되지 않은 빈칸이 없는 경우
            int backDir = (dir + 2) % 4; // 후진 방향
            if (room[y + dy[backDir]][x + dx[backDir]] != 1) {
                y += dy[backDir];
                x += dx[backDir];
            } else {
                // 뒤쪽이 벽이라 후진할 수 없는 경우 작동 중지
                break;
            }
        } else {
            // 4. 청소되지 않은 빈칸이 있는 경우
            dir = (dir + 3) % 4; // 반시계 방향 90도 회전
            if (room[y + dy[dir]][x + dx[dir]] == 0) {
                y += dy[dir];
                x += dx[dir];
            }
        }
    }

    cout << result;
    return 0;
}
```