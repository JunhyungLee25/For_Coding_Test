#include<iostream>
using namespace std;

int N,H,M;
int map[31][11];

bool check(){
    for(int i=0; i<N; i++){
        int c=i;
        for(int r=1; r<=H; r++){
            if(map[r][c]==1) c++;
            else if(c>0 && map[r][c-1]==1) c--;
        }
        if(c!=i) return false;
    }
    return true;
}
void Ladder(int sr, int sc, int cnt, int limit){
    if(cnt==limit){
        if(check()){
            cout << cnt;
            exit(0);
        }
        return ;
    }
    for(int r=sr; r<=H; r++){
        sc = (r==sr) ? sc : 0;
        for(int c=sc; c<N-1; c++){
            if(map[r][c]==0){
                if((c==0 || map[r][c-1]==0) && map[r][c+1]==0){
                    map[r][c]=1;
                    Ladder(r,c+2,cnt+1,limit);
                    map[r][c]=0;
                } 
            }
        }
    }
}
int main(void){
    cin >> N >> M >> H;
    for(int i=0; i<M; i++){
        int rr,cc;
        cin >> rr >> cc;
        map[rr][cc-1]=1;
    }
    for(int i=0; i<=3; i++){
        Ladder(0,0,0,i);
    }
    cout << -1;
    return 0;
}