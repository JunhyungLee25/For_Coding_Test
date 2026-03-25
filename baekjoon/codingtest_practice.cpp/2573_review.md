- 문제 복기
1. 처음에 설계 없이 바로 코드 구현에 들어갔더니 잔실수가 많았다. 앞으로는 길이 보여도 미리 적어놓고 차근차근 구현해야겠다.
2. 원본과 복사본을 혼용해서 사용해서 코드가 무한루프에 걸려 시간초과가 발생했다. 항상 원본 -> 복사본, 복사본 -> 원본 방식을 잘 생각하며 짜야겠다.

- 코드 동작 방식
1. 초기화: visited배열 초기화, 복사본 -> 원본 복사
2. find() 함수 실행 -> 현재 빙산이 2개 이상의 구역으로 나누어 있는지 확인한다.
3. melting() 함수 실행 -> 문제 규칙에 따라 상,하,좌,우에 바다면 갯수 만큼 얼음을 녹인다.
4. result++ -> 이 모든 과정이 끝나면 1년 증가시킨다.


- 최종 코드
```c++
#include<iostream>
using namespace std;

int N,M,result;
bool flag;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int map[301][301];
int cpmap[301][301];
bool visited[301][301];

void cp_map(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            map[i][j] = cpmap[i][j];
        }
    }
}

void melting(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]>0){
                for(int k=0; k<4; k++){
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(map[ny][nx]==0){
                        cpmap[i][j]--;
                        if(cpmap[i][j]==0){
                            break;
                        }
                    }
                }
            }
        }
    }
    cp_map();
}

void DFS(int y, int x){
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(visited[ny][nx]==0 && map[ny][nx]>0){
            visited[ny][nx]=1;
            DFS(ny,nx);
        }
    }
}

int find(int cnt){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]!=0 && visited[i][j]==0){
                visited[i][j]=0;
                DFS(i,j);
                cnt++;
            }
        }
    }
    return cnt;
}

void init_visit(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            visited[i][j]=0;
        }
    }
}

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cpmap[i][j] = map[i][j];
        }
    }

    while(1){
        cp_map();
        init_visit();
        int k= find(0);
        if(k>=2){
            cout << result;
            break;
        } else if(k==0){
            cout << 0;
            break;
        }
        result++;
        melting();
    }

    return 0;
}
```