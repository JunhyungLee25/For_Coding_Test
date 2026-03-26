- 문제 복기
1. 접근 방식: 중심 부터 시작해서 방향을 두 번 바꿀 때마다 1씩 증가하는 알고리즘을 구현하려고 했는데, 머리가 안돌아가서 실패했다... 그래서 그냥 (0,0)부터 시작해서 인덱스를 넘어가거나 이미 값이 채워져 있으면 방향을 바꾸는 직관적인 알고리즘으로 구현하였다.
2. 구현 중에 인덱스 원본값 y,x를 직접 업데이트 하다가 segment fault가 발생하였다. 범위를 벗어나면 ny,nx에서 바꾸는게 아니라 원본을 기준으로 값을 업데이트 해야함을 다시 인식했다.
```c++
// segment fault
 for(int i=N*N; i>0; i--){
        map[y][x] = i;
        y = y + dy[k%4];
        x = x + dx[k%4];
        if(y<0||x<0||y>=N||x>=N||map[y][x]!=0){
            k++;
            y = y + dy[k%4];
            x = x + dx[k%4];
        }        
    }
// 수정
for(int i=N*N; i>0; i--){
        map[y][x] = i;
        int ny = y + dy[k%4];
        int nx = x + dx[k%4];
        if(ny<0||nx<0||ny>=N||nx>=N||map[ny][nx]!=0){
            k++;
            ny = y + dy[k%4];
            nx = x + dx[k%4];
        }  
        y = ny;
        x = nx;      
    }
```

- 최종 코드
```c++
#include<iostream>
using namespace std;

int N,num,r,c;
// 아,오,위,왼
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

int map[1000][1000];

void snail(int y, int x){
    int k=0;
    for(int i=N*N; i>0; i--){
        map[y][x] = i;
        int ny = y + dy[k%4];
        int nx = x + dx[k%4];
        if(ny<0||nx<0||ny>=N||nx>=N||map[ny][nx]!=0){
            k++;
            ny = y + dy[k%4];
            nx = x + dx[k%4];
        }  
        y = ny;
        x = nx;      
    }
}

int main(void){
    cin >> N >> num;
    snail(0,0);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << map[i][j] << ' ';
            if(map[i][j]==num){
                r=i+1;
                c=j+1;
            }
        }
        cout << '\n';
    }
    cout << r << ' ' << c;
    return 0;
}
```

## 가운데부터 시작하는 방식

기존 방식과 다르게 for문을 가야할 거리만큼 반복하고 dir을 고정한다. 가야할 거리를 다 가고 나면 방향이 전환되고 moveCount가 증가한다. moveCount가 2번 증가하면 방향을 두 번 꺾었으므로 이동 거리가 1 증가하게 된다.

```c++
#include <iostream>
#include <vector>
using namespace std;
int N, target;
int board[1001][1001];
int ansY, ansX;
// 이동 방향: 위, 오른쪽, 아래, 왼쪽 (중심에서 바깥으로 나가는 순서)
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
void solve() {
    int y = N / 2;
    int x = N / 2;
    int num = 1;
    int dist = 1;      // 현재 방향으로 이동할 거리
    int dir = 0;       // 현재 방향 인덱스
    int moveCount = 0; // 같은 거리로 몇 번 이동했는지 카운트
    board[y][x] = num;
    while (num < N * N) {
        // 현재 설정된 dist만큼 해당 방향으로 이동
        for (int i = 0; i < dist; i++) {
            y += dy[dir];
            x += dx[dir];
            num++;
            board[y][x] = num;
            // 목표 숫자 좌표 저장
            if (num == target) {
                ansY = y + 1;
                ansX = x + 1;
            }
            // N*N까지 다 채웠으면 즉시 종료
            if (num == N * N) break;
        }
        if (num == N * N) break;
        // 방향 전환
        dir = (dir + 1) % 4;
        moveCount++;
        // 두 번 방향을 꺾었으면 이동 거리 1 증가
        if (moveCount == 2) {
            dist++;
            moveCount = 0;
        }
    }
    // target이 1인 경우 초기값 설정
    if (target == 1) {
        ansY = N / 2 + 1;
        ansX = N / 2 + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> target;

    solve();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << ansY << " " << ansX << "\n";

    return 0;
}
```