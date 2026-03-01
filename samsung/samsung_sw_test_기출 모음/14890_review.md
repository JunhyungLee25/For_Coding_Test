## 1. 문제 분석

이 문제는 $N \times N$ 격자에서 각 행과 열이 '지나갈 수 있는 길'인지 판단하는 시뮬레이션 문제이다.

- **핵심 로직 (3단계)**:
    
    1. **연속성 확인**: 길을 검사하며 인접한 칸의 높이 차이를 계산한다. 동일한 높이이면 연속된 길의 길이(`length++`)를 추가한다.
        
    2. **경사로 설치 조건 확인**:
        
        - **오르막길**: 현재 칸이 이전 칸보다 1 높을 때, 지금까지 지나온 평지의 길이(`length`)가 경사로의 길이($L$)보다 크거나 같은지 확인한다. 이때 이미 내리막 경사로가 설치된 칸(`selected`)인지도 함께 확인해야 한다.
            
        - **내리막길**: 현재 칸이 이전 칸보다 1 낮을 때, 앞으로 나올 $L$개의 칸이 모두 같은 높이인지, 그리고 범위를 벗어나지 않는지 미리 확인한다.
            
    3. **예외 처리 및 카운트**: 높이 차이가 2 이상이거나, 경사로를 설치할 수 없는 조건인 경우 해당 길을 즉시 포기(`flag = false`)한다. 모든 조건을 통과한 행과 열의 개수를 합산한다.
        

---

## 2. 배운 점

- (1) **내리막길 처리의 특수성**: 오르막길은 지나온 길의 정보(`length`)만으로 판단이 가능하지만, 내리막길은 앞으로 올 칸들을 **미리 확인**해야 한다. 이를 위해 별도의 루프를 사용하여 미래의 $L$개 칸을 검사하는 로직의 중요성을 배웠다.
    
- (2) **중복 설치 방지 (`selected` 배열)**: 내리막 경사로를 설치한 지점에 바로 이어서 오르막 경사로를 설치해야 하는 경우 등 경사로가 겹치는 상황을 방지하기 위해 방문 처리 배열(`selected`)을 활용하는 법을 익혔다.
    
    - 잘못 생각한 부분: 처음에는 단순히 `length` 변수 하나로만 처리하려 했으나, 내리막 경사로가 끝난 지점이 바로 오르막의 시작점이 될 때 `length`가 꼬이는 문제가 발생했다. `selected` 배열을 통해 물리적으로 경사로가 점유한 칸을 명확히 표시함으로써 문제를 해결할 수 있었다.
        

---

## 3. 최종 코드 및 동작 방식 정리

가로(`garo`)와 세로(`sero`) 방향에 대해 각각 함수를 실행한다. 각 함수는 한 줄을 순차적으로 탐색하며 높이 차이에 따른 경사로 설치 가능 여부를 판단한다.

### garo / sero 함수 작동 방식

- **작동 방식**:
    
    1. **높이 차이 계산**: `map[i-1] - map[i]`를 통해 경사도를 파악한다.
        
    2. **평지 처리**: 차이가 0이면 `length`를 증가시키고 다음 칸으로 이동한다.
        
    3. **오르막 처리**: 높이가 1 높아진 경우, 현재까지의 `length`가 $L$ 이상인지 확인한다. 또한 `selected` 배열을 역으로 조회하여 이미 경사로가 있는지도 체크한다.
        
    4. **내리막 처리**: 높이가 1 낮아진 경우, 현재 위치를 포함해 $L$개 칸의 높이가 동일한지 루프를 돌며 확인한다. 조건을 만족하면 `selected` 배열에 표시하고 `length`를 초기화한다.
        
    5. **반복문 제어**: 내리막이나 오르막 검사 중 `flag`가 `false`가 되면 안쪽 루프뿐만 아니라 전체 루프를 `break`로 탈출하여 불필요한 연산을 방지한다.
        

```c++
#include<iostream>
using namespace std;

int N, L, cnt;
int map[101][101];

void garo(int y) {
    int length = 1;
    bool flag = true;
    int selected[101] = { 0 };

    for (int i = 1; i < N; i++) {
        int diff = map[y][i - 1] - map[y][i];

        if (diff == 0) {
            length++;
        }
        else if (diff == -1) { // 오르막길
            if (length < L) {
                flag = false;
                break;
            }
            for (int j = 1; j <= L; j++) {
                if (i - j >= 0 && selected[i - j] == 1) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
            length = 1;
        }
        else if (diff == 1) { // 내리막길
            if (N - i < L) {
                flag = false;
                break;
            }
            for (int j = 0; j < L; j++) {
                if (map[y][i + j] == map[y][i]) {
                    selected[i + j] = 1;
                }
                else {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
            i += (L - 1); // 경사로 길이만큼 점프
            length = 0;
        }
        else { // 높이 차이 2 이상
            flag = false;
            break;
        }
    }
    if (flag) cnt++;
}

void sero(int x) {
    int length = 1;
    bool flag = true;
    int selected[101] = { 0 };

    for (int i = 1; i < N; i++) {
        int diff = map[i - 1][x] - map[i][x];

        if (diff == 0) {
            length++;
        }
        else if (diff == -1) {
            if (length < L) {
                flag = false;
                break;
            }
            for (int j = 1; j <= L; j++) {
                if (i - j >= 0 && selected[i - j] == 1) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
            length = 1;
        }
        else if (diff == 1) {
            if (N - i < L) {
                flag = false;
                break;
            }
            for (int j = 0; j < L; j++) {
                if (map[i + j][x] == map[i][x]) {
                    selected[i + j] = 1;
                }
                else {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
            i += (L - 1);
            length = 0;
        }
        else {
            flag = false;
            break;
        }
    }
    if (flag) cnt++;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        garo(i);
        sero(i);
    }

    cout << cnt;
    return 0;
}
```