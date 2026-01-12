#include<iostream>
using namespace std;

int main(){
    // 1<= H,W <= 99
    int T;
    int H, W, N;
    int a[1000];
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> H >> W >> N;
        if(N % H == 0){
            a[i] = (100*H) +(N / H) + 1;
        }
        else {
            a[i] = 100*(N % H)+(N / H) + 1;
        }
    }
    for(int i=0; i<T; i++){
        cout << a[i] << '\n';
    }
}