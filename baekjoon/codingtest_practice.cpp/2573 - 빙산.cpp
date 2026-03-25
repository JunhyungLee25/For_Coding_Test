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