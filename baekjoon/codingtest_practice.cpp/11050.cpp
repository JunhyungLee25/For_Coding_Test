#include<iostream>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    int X = 1;
    
    for(int i=N; i>N-K; i--){
        X *= i;
    }
    for(int j=K; j>=1; j--){
        X /= j;
    }
    cout << X;
}