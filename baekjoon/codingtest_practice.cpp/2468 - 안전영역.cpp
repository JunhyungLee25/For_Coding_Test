/*
NxN
안전영역: 물에 잠기지 않는 지점들 -> 위,아래,오른쪽,왼쪽 인접해있으면 하나의 영역임.
*/
#include<iostream>
using namespace std;

int N,H;
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

int map[101][101];
bool visited[101][101];

void DFS(int r, int c, int h){    
    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr<0||nc<0||nr>=N||nc>=N) continue;
        if(visited[nr][nc]==0 && map[nr][nc]>h){
            visited[nr][nc]=1;
            DFS(nr,nc,h);
        }
    }
}

void init_visit(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            visited[i][j]=0;
        }
    }
}
int main(void){
    cin >> N;
    int MAX_H=0,MAX_RESULT=0;
    int cnt[101]={0};
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
            if(map[i][j] > MAX_H){
                MAX_H = map[i][j];
            }
        }
    }

    for(int h=1; h<=MAX_H; h++){
        init_visit();
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(visited[i][j]==0 && map[i][j]>h){
                    DFS(i,j,h);
                    cnt[h]++;
                }
            }
        }
    }
    for(int i=1; i<=MAX_H; i++){
        if(MAX_RESULT<cnt[i]){
            MAX_RESULT = cnt[i];
        }
    }    
    if(MAX_RESULT==0){
        cout << 1;
    } else{
        cout << MAX_RESULT;
    }
    return 0;
}