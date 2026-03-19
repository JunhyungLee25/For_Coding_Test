/*
배열 크기: NxM
N,M중 작은 값은 2의 배수 -> 돌리기 불가능 없애려고

1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1

배열 돌리기: 반시계 방향으로 한칸씩 민다.

배열 돌리기 경우의 수
1. (r,c) -> (r+1,c) y++ DOWN
2. (r,c) -> (r,c+1) x++ RIGHT
3. (r,c) -> (r-1,c) y-- UP
4. (r,c) -> (r,c-1) x-- LEFT

제일 바깥쪽 (0,0) 부터 시작 (N-1)번수행 -> (M-1)번 수행 -> (N-1)번 수행 -> (M-1)번 수행
그 다음 바깥쪽 (1,1)존재하면 시작 (N-2-1)번 수행 -> (M-2-1)번 수행 ...

*/

#include<iostream>
using namespace std;

#define MAX (300+1)

int N,M,R;
int map[MAX][MAX];
int nmap[MAX][MAX];

void counterclockwise_list(int y, int x, int r, int c){
    for(int i=0; i<r-1; i++){
        nmap[y+1+i][x] = map[y+i][x];
    }
    for(int i=0; i<c-1; i++){
        nmap[y+r-1][x+1+i] = map[y+r-1][x+i];
    }
    for(int i=0; i<r-1; i++){
        nmap[y+r-1-1-i][x+c-1] = map[y+r-1-i][x+c-1]; 
    }
    for(int i=0; i<c-1; i++){
        nmap[y][x+c-1-1-i] = map[y][x+c-1-i];
    }
}


int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> R;
    // input, 초기화
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
            nmap[i][j]=0;
        }
    }
    // 배열 돌리기 가능 찾기
    int cnt=1;
    for(int i=1; i<MAX; i++){
        if((N-2*i-1)>=1 && (M-2*i-1)>=1){
            cnt++;
        } else break;
    }
    // 동작
    while(R--){
        for(int i=0; i<cnt; i++){
            counterclockwise_list(i,i,N-(i*2),M-(i*2));
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                map[i][j] = nmap[i][j];
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}