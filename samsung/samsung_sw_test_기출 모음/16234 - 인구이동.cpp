#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int N,L,R;
int day,sum,cnt;
int map[51][51];
bool visited[51][51];
vector<pair<int,int>> crew;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
void find(int y, int x){
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if((0<=ny&&ny<N)&&(0<=nx&&nx<N)&&visited[ny][nx]==false && L<=abs(map[ny][nx]-map[y][x])&&abs(map[ny][nx]-map[y][x])<=R){
            visited[ny][nx]=true;
            crew.push_back({ny,nx});
            sum += map[ny][nx];
            cnt ++;
            find(ny,nx);
        }
    }
}
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> L >> R;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }
    while(true){ // 인구 이동이 없을 때까지 반복
        bool moved = false;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                visited[i][j]=0;
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(visited[i][j]==false){
                    crew.clear();
                    crew.push_back({i,j});
                    sum=map[i][j];
                    cnt=1;
                    visited[i][j]=true;
                    find(i,j);
                    if(crew.size() > 1){ // 연합이 형성(국경 개방 국가가 2개 이상) 되었다면
                        moved = true;
                        int avg = sum/cnt;
                        for(int k=0; k<crew.size(); k++){
                            map[crew[k].first][crew[k].second] = avg;
                        }
                    }
                }
            }
        }
        if(!moved) break; // 하루동안 아무런 인구 이동이 없었다면 종료
        day++;
    }
    cout << day;
    return 0;
}