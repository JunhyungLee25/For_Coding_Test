#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int v = 0;
    while(N>=0){
        if(N%5==0){
            v += N / 5;
            cout << v;
            return 0;
        }
        N -= 3;
        v++;
    }
    cout << -1;
    return 0;
}