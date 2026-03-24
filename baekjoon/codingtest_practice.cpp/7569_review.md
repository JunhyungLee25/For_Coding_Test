- **복기**
1. tuple 사용법에 대해 익혔다.
2. 3차원 배열로 입력이 주어셔서 기존 과 다르게 M,N,H 순으로 주어졌는데 아무생각없이 N,M,H 순으로 받아서 index오류가 발생하였다.
3. 3차원 배열에서의 BFS를 공부할 수 있었다.

- **최종 코드**

```c++
/*
1: 익은 토마토
0: 익지 않은 토마토
-1: 없음
*/

#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int N,M,H;

// 위,아래,상,우,하,좌
int dz[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,-1,0,1,0};
int dx[6] = {0,0,0,1,0,-1};

//z,y,x
int map[101][101][101];
bool visited[101][101][101];

int main(void){
    cin >> M >> N >> H;
    queue<tuple<int,int,int>> q;
    int Max_result = 0;
    int tomato = 0;
    // input
    for(int z=0; z<H; z++){
        for(int y=0; y<N; y++){
            for(int x=0; x<M; x++){
                cin >> map[z][y][x];
            }
        }
    }
    // 익은 토마토 찾기 && 종료 조건 (1)
    for(int z=0; z<H; z++){
        for(int y=0; y<N; y++){
            for(int x=0; x<M; x++){
                if(map[z][y][x]==1){
                    q.push({z,y,x});
                    visited[z][y][x] =1;
                } else if(map[z][y][x]==0){
                    tomato++;
                }      
            }
        }
    }
    // 0(안익은 토마토)가 없으면 0 출력하고 종료.
    if(tomato==0){
        cout << 0;
        return 0;
    } 
    
    // BFS
    while(!q.empty()){
        tuple<int,int,int> curr = q.front();
        q.pop();
        int cz = get<0>(curr);
        int cy = get<1>(curr);
        int cx = get<2>(curr);
        for(int dir=0; dir<6; dir++){
            int nz = cz + dz[dir];
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if(nz<0||ny<0||nx<0||nz>=H||ny>=N||nx>=M) continue;
            if(visited[nz][ny][nx]==0 && map[nz][ny][nx]==0){
                q.push({nz,ny,nx});
                visited[nz][ny][nx] = true;
                map[nz][ny][nx]=map[cz][cy][cx] + 1;
            }
        }
    }

    // 최소 며칠이 걸리는지, 안 익은 토마토가 있는지 확인
    for(int z=0; z<H; z++){
        for(int y=0; y<N; y++){
            for(int x=0; x<M; x++){
                if(map[z][y][x]>Max_result){
                    Max_result = map[z][y][x];
                }
                if(map[z][y][x]==0){
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << Max_result-1;
    return 0;
}
```