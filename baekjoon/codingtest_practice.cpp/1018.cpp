#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string WB[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};
string BW[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};
string Chess[50];
int WBpaint(int x, int y){
    int paint = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(Chess[i+x][j+y] != WB[i][j]){
                paint++;
            }
        }
    }
    return paint;
}
int BWpaint(int x, int y){
    int paint = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(Chess[i+x][j+y] != BW[i][j]){
                paint++;
            }
        }
    }
    return paint;
}
int main(){
    int N,M;
    cin >> N >> M;
    int minval = 64;
    for(int i=0; i<N; i++){
        cin >> Chess[i];
    }
    for(int i=0; i<=N-8; i++){
        for(int j=0; j<=M-8; j++){
            int val = 0;
            val = min(WBpaint(i,j),BWpaint(i,j));
            if(val < minval){
                minval = val;
            }
        }
    }
    cout << minval;
    return 0;
}