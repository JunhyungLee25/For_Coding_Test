#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int map[8][8];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int n,m;
struct CCTV {
    int y,x,type;
};
vector<CCTV> cctv_list;
int ans=10000000;
void find(int tp[8][8]){
    int result=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tp[i][j]==0) result++;
        }
    }
    ans = min(ans, result);
}
void ob(int y, int x, int dir, int tp[8][8]){
    while(1){
        y+=dy[dir];
        x+=dx[dir];
        if((0<=y&&y<n)&&(0<=x&&x<m)&&map[y][x]!=6) tp[y][x]=7;
        else break;
    }
    return ;
}
void cpMap(int cp[8][8], int map[8][8]){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cp[i][j]=map[i][j];
        }
    }
}
void bt(int idx, int cm[8][8]){
    if(idx == cctv_list.size()){
        // 현재 최소크기 저장
        find(cm);
        return ;
    }
    int ctype = cctv_list[idx].type;
    int cy = cctv_list[idx].y;
    int cx = cctv_list[idx].x;

    for(int dir=0; dir<4; dir++){
        int cp_map[8][8];
        cpMap(cp_map,cm);
        if(ctype==1){
            ob(cy,cx,dir,cp_map);
        } else if(ctype==2){
            if(dir>=2){
                bt(idx+1,cp_map);
                break;
            } 
            ob(cy,cx,dir,cp_map);
            ob(cy,cx,dir+2,cp_map);
        } else if(ctype==3){
            ob(cy,cx,dir,cp_map);
            ob(cy,cx,(dir+1)%4,cp_map);
        } else if(ctype==4){
            ob(cy,cx,dir,cp_map);
            ob(cy,cx,(dir+1)%4,cp_map);
            ob(cy,cx,(dir+2)%4,cp_map);
        } else if(ctype==5){
            ob(cy,cx,dir,cp_map);
            ob(cy,cx,(dir+1)%4,cp_map);
            ob(cy,cx,(dir+2)%4,cp_map);
            ob(cy,cx,(dir+3)%4,cp_map);
            bt(idx+1,cp_map);
            break;
        } 
        bt(idx+1,cp_map);
    }
}
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int result=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(1<=map[i][j]&&map[i][j]<=5){
                cctv_list.push_back({i,j,map[i][j]});
            }
        }
    }
    bt(0,map);
    cout << ans;
    return 0;
}