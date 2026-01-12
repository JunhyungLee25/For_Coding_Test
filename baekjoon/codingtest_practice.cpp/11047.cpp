#include<iostream>
using namespace std;
int N,K; // N : 동전의 종류,K : 만들어야 하는 액수
int coin[10];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> K;
    int min=0;
    for(int i=0; i<N; i++){
        cin >> coin[i];
    }
    for(int i=N-1; i>=0; i--){
        int a = K / coin[i];
        K -= a*coin[i];
        min += a; 
    }
    cout << min;
    return 0;
}