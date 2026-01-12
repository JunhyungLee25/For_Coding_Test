// 4 <= N <= 50 : 격자 크기, 0 <= M <= N^2 : 파이어볼 개수, 1 <= K <= 1,000 : 명령 수
// 파이어볼 정보 : 1 <= (r,c) <= N : 좌표, 1 <= m <= 1,000 : 질량, 1 <= s <= 1,000 속력 , d : 방향
// 파이어볼 방향 : 0,1,2,3,4,5,6,7
// 좌표는 연결되어있음. 
#include<iostream>
#include<vector>
using namespace std;

struct FIREBALL{
    int x;
    int y;
    int weight;
    int speed;
    int direction;
};
vector<FIREBALL> fireballs;
int go_x[8] = {0,1,1,1,0,-1,-1,-1};
int go_y[8] = {1,1,0,-1,-1,-1,0,1}; 
void do_fireball(int k){

}


int main(void){
    int N,M,K;
    cin >> N >> M >> K;
    int r,c,m,s,d;
    while(M--){
        FIREBALL ball;
        cin >> r >> c >> m >> s >> d;
        ball = {r,c,m,s,d};
    }
    do_fireball(K);
    return 0;
}