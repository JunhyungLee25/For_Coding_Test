#include<iostream>
using namespace std;
int room[50][50];
int dy[4] = {-1,0,1,0,};
int dx[4] = {0,1,0,-1};
int result = 0;
int main(void){
    int n,m,x,y,dir;
    cin >> n >> m;
    cin >> y >> x >> dir;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> room[i][j];
        }
    }
    while(true){
        if(room[y][x]==0){room[y][x]=2; result++;}
        bool found=false;
        for(int i=0; i<4; i++){
            if(room[y+dy[i]][x+dx[i]]==0){
                found = true;
                break;
            }    
        }
        if(!found){
            int counter = (dir+2)%4;
            if(room[y+dy[counter]][x+dx[counter]]!=1){
                y += dy[counter];
                x += dx[counter]; 
            } else {break;}
        } else {
            dir = (dir+3)%4;
            if(room[y+dy[dir]][x+dx[dir]]==0){
                y += dy[dir];
                x += dx[dir];
            }
        }
    }
    cout << result;
    return 0;
}