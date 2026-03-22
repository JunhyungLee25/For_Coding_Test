#include<iostream>
#include<algorithm>
using namespace std;
int N,M,R;
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
int map[301][301];
void rotate(int i){
    int startVal = map[i][i];
    int k = 0;
    int r = i;
    int c = i;
    while(k<4){
        int nr = r + dr[k];
        int nc = c + dc[k];
        if(nr==i && nc==i) break;
        if(nr >= i && nc >= i && nr < N-i && nc < M-i){
            map[r][c] = map[nr][nc];
            r = nr;
            c = nc;
        }
        else{k++;}
    }
    map[i+1][i] = startVal;
}

int main(void){
    cin >> N >> M >> R;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
    int cnt = min(N,M)/2;
    for(int i=0; i<cnt; i++){
        int k = R % (2*(N+M)-4);
        for(int j=0; j<k; j++){
            rotate(i);
        }
        N-=2;
        M-=2;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << map[i][j] << ' '; 
        }
        cout << '\n';
    }
    return 0;
}