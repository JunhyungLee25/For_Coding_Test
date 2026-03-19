// 배열 돌리기
#include<iostream>
using namespace std;

#define MAX (501)
int T,N,D,cnt; // D>0 시계, D<0 반시계, 횟수: |D|/45
int map[MAX][MAX];
int nmap[MAX][MAX];

// X를 시계 방향으로 45도 돌리면
// 주 대각선((1,1),(2,2)...(n,n)) -> ((n+1)/2번째 열)로 이동
// 가운데 열 -> 부 대각선((n,1),(n-1,2)...(1,n))로 이동
// 부 대각선 -> 가운데 행 (n+1)/2번째
// 가운데 행 -> 주 대각선
// 원본 순서 유지
// 다른 원소 위치는 그대로
// 1,1 -> 1,(n+1)/2 2,2 2,(n+1)
void clockwise45(){
    while(cnt--){
        // 원본 -> 카피
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                nmap[i][j] = map[i][j];
            }
        }
        
        int mid = (N-1)/2;
        for(int i=0; i<N; i++){
            nmap[i][mid] = map[i][i];// 주 대각선 -> 가운데 열 
        }   
        for(int i=0; i<N; i++){
            nmap[i][N-1-i] = map[i][mid];// 가운데 열 -> 부 대각선
        }
        for(int i=0; i<N; i++){
            nmap[mid][i] = map[N-1-i][i];// 부 대각선 -> 가운데 행
        }
        for(int i=0; i<N; i++){
            nmap[i][i] = map[mid][i];// 가운데 행 -> 주 대각선
        }
        
        // 결과 -> 원본
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                map[i][j] = nmap[i][j];
            }
        }
    }
}

// X를 시계 반대방향으로 45도 돌리면
// 주 대각선 -> 가운데 행
// 가운데 행 -> 부 대각선
// 부 대각선 -> 가운데 열
// 가운데 열 -> 주 대각선
// 원본 순서 유지
// 다른 원소 위치는 그대로
void counterclockwise45(){
    while(cnt--){
        // 원본 -> 카피
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                nmap[i][j] = map[i][j];
            }
        }
        
        int mid = (N-1)/2;
        for(int i=0; i<N; i++){
            nmap[mid][i] = map[i][i];// 주 대각선 -> 가운데 행 
        }   
        for(int i=0; i<N; i++){
            nmap[N-1-i][i] = map[mid][i];// 가운데 행 -> 부 대각선
        }
        for(int i=0; i<N; i++){
            nmap[i][mid] = map[i][N-1-i];// 부 대각선 -> 가운데 열
        }
        for(int i=0; i<N; i++){
            nmap[i][i] = map[i][mid];// 가운데 열 -> 주 대각선
        }

        // 결과 -> 원본
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                map[i][j] = nmap[i][j];
            }
        }
    }
}

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    
    for(int p=0; p<T; p++){
        cin >> N >> D;
        // 초기화
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                map[i][j]=0;
                nmap[i][j]=0;
            }
        }
        // input
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> map[i][j];
            }
        }
        // 동작
        if(D<0){
            cnt = (-D)/45;
            counterclockwise45();
        } 
        else{
            cnt = D/45;
            clockwise45();
        } 
        // output
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << map[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}