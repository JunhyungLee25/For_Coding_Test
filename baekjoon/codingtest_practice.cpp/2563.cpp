#include<iostream>
using namespace std;
int map[100][100];
int main(void){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        for(int j=x; j<x+10; j++){
            for(int k=y; k<y+10; k++){
                map[k][j]=1;
            }
        }
    }
    int cnt=0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(map[i][j]==1) cnt++;
        }
    }
    cout << cnt;
    return 0;
}

/*
큰 정사각형을 이차원 배열로 생각하고, 입력받은 작은 정사각형이 존재하는 부분을 1로 생각한다.
중복되는 부분을 고려할 필요없이 큰 정사각형에서 1인 부분만을 세면 총 넓이를 얻을 수 있다.
*/