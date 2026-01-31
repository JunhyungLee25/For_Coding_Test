#include<iostream>
using namespace std;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int n;
int map[500][500];
int sdy[4][9] = {
                { 1, 1, 0, 0, 0, 0, -1, -1, -2 },  // 0
                { -1, 1, -2, 2, -1, 1, -1, 1, 0 }, // 1
                { -1, -1, 0, 0, 0, 0, 1, 1, 2 },   // 2
                { -1, 1, -2, 2, -1, 1, -1, 1, 0 }  // 3
                };
int sdx[4][9] = {
                { -1, 1, -2, 2, -1, 1, -1, 1, 0 }, // 0
                { -1, -1, 0, 0, 0, 0, 1, 1, 2 },   // 1
                { -1, 1, -2, 2, -1, 1, -1, 1, 0 }, // 2
                { 1, 1, 0, 0, 0, 0, -1, -1, -2 }   // 3
                };
int rates[9] = {1,1,2,2,7,7,10,10,5};
int out_map = 0;
void move_sand(int dir,int y, int x){
    int tot_sand = map[y][x];
    int tmp = 0;
    for(int i=0; i<9; i++){
        int ny = y + sdy[dir][i];
        int nx = x + sdx[dir][i];
        int sand = (rates[i]*tot_sand)/100;
        if((0<= ny && ny <n) && (0<= nx && nx <n)){
            map[ny][nx] += sand;
        } else {
            out_map += sand;
        }
        tmp += sand;
    }
    int ay = y + dy[dir];
    int ax = x + dx[dir];
    if((0<= ay && ay <n) && (0<= ax && ax <n)){
            map[ay][ax] += tot_sand - tmp;
    } else {
        out_map += tot_sand - tmp;
    }
    map[y][x]=0;
}
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    int r = n/2;
    int c = n/2;
    int idx=3;
    int dist = 1;
    while(1){
        for(int i=0; i<2; i++){
            for(int j=0; j<dist; j++){
                r += dy[idx];
                c += dx[idx];
                move_sand(idx,r,c);
                if(r ==0 && c==0){
                    cout << out_map;
                    return 0;
                } 
            }
            idx = (idx+3)%4;
        }
        dist++;
    }
    return 0;
}