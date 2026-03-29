- 문제 복기
1. 시작점이 여러개이고 최단거리(시간)을 구해야할 때는 모든 시작점을 한 번에 큐에 넣고 시작해야 더 빠르고 효율적으로 계산할 수 있다.
2. N,M 입력 순서를 잘보자...
3. 시간+1을 해줄 때, 변수를 증가시키는게 아니라 기준점의 값+1을 해주어야 정확하게 계산이 가능하다.
4. 큐에 추가하는 기준을 각 토마토 사이의 시간값으로 비교하기 때문에 방문한곳은 재방문 할 일이 없기 때문에 `visited`배열은 사용하지 않았다.
5. 이미 다 익은 상태라면 0을 출력하는 부분은 처음에 다 검사해서 진행할 수도 있지만 어차피 다 1이라면 BFS로 바로 종료되고 최대 시간이 1이므로 결국 0이 출력되게 되기 때문에 예외처리 코드를 만들지 않았다.

- 최종 코드
```c++
#include<iostream>
#include<queue>
using namespace std;
#define MAX 1001
int N,M;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int map[MAX][MAX];
queue<pair<int,int>> q;

void BFS(){
    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int dir=0; dir<4; dir++){
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if(ny<0||nx<0||ny>=N||nx>=M) continue;
            if(map[ny][nx]==0 || map[ny][nx]>map[cy][cx]+1){
                map[ny][nx]=map[cy][cx]+1;
                q.push({ny,nx});
            }
        }
    }
}

int main(void){
    cin >> M >> N;
    int day=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]==1){
                q.push({i,j});
            }
        }
    }
    BFS();
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(day<map[i][j]){
                day = map[i][j];
            } else if(map[i][j]==0){
                cout << -1;
                return 0;
            }
        }
    }
    cout << day-1;
    return 0;
}
```