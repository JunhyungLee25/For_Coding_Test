**실수 복기**
- 처음에 버벅인 이유: 3,4번 구현에서 단순히 돌리는게 아니라 N,M의 길이 즉 행,열의 길이가 바뀌는데 그걸 생각안하고 풀어서 더 복잡한 형태로 구현하려고 했고 미궁에 빠졌다.
- 문제 잘 읽고, 헷갈리면 직접 적으며 풀자

**함수별 작동 방식:**

- **cal_1 / cal_2**: 대칭 축을 기준으로 데이터를 맞바꾼다. 상하는 행($i$)을 $N-1-i$로, 좌우는 열($j$)을 $M-1-j$로 매핑한다.
    
- **cal_3 / cal_4**: 90도 회전을 수행한다. `tp` 변수로 기존 크기를 저장한 후 $N$과 $M$을 스왑한다. 시계 방향은 `map[tp-1-j][i]`, 반시계 방향은 `map[j][tp-1-i]` 규칙을 적용한다.
    
- **cal_5 / cal_6**: 사분면 이동을 수행한다. 전체를 4개의 `for`문으로 나누어 각 구역의 시작점과 끝점을 지정하고, $N/2$ 또는 $M/2$만큼 인덱스를 가감하여 이동시킨다.
    

```c++
#include<iostream>
using namespace std;

int N, M, R;
int map[101][101];
int cpmap[101][101];

// 임시 배열의 내용을 원본 배열로 복사
void COPY_MAP() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            map[i][j] = cpmap[i][j];
        }
    }
}

// 1번: 상하 반전
void cal_1() {
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < M; j++) {
            cpmap[i][j] = map[N - 1 - i][j];
            cpmap[N - 1 - i][j] = map[i][j];
        }
    }
    COPY_MAP();
}

// 2번: 좌우 반전
void cal_2() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M / 2; j++) {
            cpmap[i][M - 1 - j] = map[i][j];
            cpmap[i][j] = map[i][M - 1 - j];
        }
    }
    COPY_MAP();
}

// 3번: 오른쪽 90도 회전
void cal_3() {
    int tp = N;
    N = M;
    M = tp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cpmap[i][j] = map[tp - 1 - j][i];
        }
    }
    COPY_MAP();
}

// 4번: 왼쪽 90도 회전
void cal_4() {
    int tp = M;
    M = N;
    N = tp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cpmap[i][j] = map[j][tp - 1 - i];
        }
    }
    COPY_MAP();
}

// 5번: 사분면 시계 방향 이동
void cal_5() {
    int hn = N / 2;
    int hm = M / 2;
    for (int i = 0; i < hn; i++) {
        for (int j = 0; j < hm; j++) {
            cpmap[i][j + hm] = map[i][j];             // 1->2
            cpmap[i + hn][j + hm] = map[i][j + hm];    // 2->3
            cpmap[i + hn][j] = map[i + hn][j + hm];    // 3->4
            cpmap[i][j] = map[i + hn][j];             // 4->1
        }
    }
    COPY_MAP();
}

// 6번: 사분면 반시계 방향 이동
void cal_6() {
    int hn = N / 2;
    int hm = M / 2;
    for (int i = 0; i < hn; i++) {
        for (int j = 0; j < hm; j++) {
            cpmap[i + hn][j] = map[i][j];             // 1->4
            cpmap[i + hn][j + hm] = map[i + hn][j];    // 4->3
            cpmap[i][j + hm] = map[i + hn][j + hm];    // 3->2
            cpmap[i][j] = map[i][j + hm];             // 2->1
        }
    }
    COPY_MAP();
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    while (R--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) cal_1();
        else if (cmd == 2) cal_2();
        else if (cmd == 3) cal_3();
        else if (cmd == 4) cal_4();
        else if (cmd == 5) cal_5();
        else if (cmd == 6) cal_6();
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
```