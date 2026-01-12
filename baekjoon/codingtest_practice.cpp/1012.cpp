#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int ground[50][50];
bool visit[50][50];
int dir_x[4] = {-1,1,0,0};
int dir_y[4] = {0,0,-1,1};

void dfs(int x, int y,int N, int M){
    visit[y][x]=true;
    for(int i=0; i<4; i++){
        int new_x = x+dir_x[i];
        int new_y = y+dir_y[i];
        if((0<= new_x && new_x < M) && (0<= new_y && new_y < N) && !visit[new_y][new_x] && ground[new_y][new_x]==1){
            
            dfs(new_x,new_y,N,M);
        }
    } 
}
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t,n,m,k,a,b;
    cin >> t;
    while(t--){
        memset(ground, 0, sizeof(ground));
        memset(visit, false, sizeof(visit));
        int cnt=0;
        cin >> m >> n >> k;
        for(int i=0; i<k; i++){
            cin >> a >> b;
            ground[b][a]=1;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visit[i][j] && ground[i][j]==1){
                    dfs(j,i,n,m);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    
   return 0; 
}