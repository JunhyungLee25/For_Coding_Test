#include<iostream>
using namespace std;

int N,num,r,c;
// 아,오,위,왼
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

int map[1000][1000];

void snail(int y, int x){
    int k=0;
    for(int i=N*N; i>0; i--){
        map[y][x] = i;
        int ny = y + dy[k%4];
        int nx = x + dx[k%4];
        if(ny<0||nx<0||ny>=N||nx>=N||map[ny][nx]!=0){
            k++;
            ny = y + dy[k%4];
            nx = x + dx[k%4];
        }  
        y = ny;
        x = nx;      
    }
}

int main(void){
    cin >> N >> num;
    snail(0,0);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << map[i][j] << ' ';
            if(map[i][j]==num){
                r=i+1;
                c=j+1;
            }
        }
        cout << '\n';
    }
    cout << r << ' ' << c;
    return 0;
}