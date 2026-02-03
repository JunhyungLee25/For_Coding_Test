#include<iostream>
using namespace std;
/*
1: 0<3, 2<0, 3<5, 5<2
2: 0<2, 2<5, 3<0, 5<3
3: 0<1, 1<5, 4<0, 5<4
4: 0<4, 1<0, 4<5, 5<1 
*/
int dice[6];
int map[20][20];
int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,cx,cy,k;
    cin >> n >> m >> cy >> cx >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<k; i++){
        int dir;
        int t1,t2,t3,t4;
        cin >> dir;
        if((0<=cy+dy[dir-1]&&cy+dy[dir-1]<n) && (0<=cx+dx[dir-1]&&cx+dx[dir-1]<m)){
            cy += dy[dir-1];
            cx += dx[dir-1];    
        } else {continue;}
        int t = dice[0];
        if(dir==1){
            dice[0] = dice[3];
            dice[3] = dice[5];
            dice[5] = dice[2];
            dice[2] = t;
        } else if(dir==2){
            dice[0] = dice[2];
            dice[2] = dice[5];
            dice[5] = dice[3];
            dice[3] = t;
        } else if(dir==3){
            dice[0] = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[4];
            dice[4] = t;
        } else{
            dice[0] = dice[4];
            dice[4] = dice[5];
            dice[5] = dice[1];
            dice[1] = t;
        }
        if(map[cy][cx]==0){
            map[cy][cx]= dice[5];
        } else {
            dice[5] = map[cy][cx];
            map[cy][cx]=0;
        }
        cout << dice[0] << '\n';
    }
    return 0;
}