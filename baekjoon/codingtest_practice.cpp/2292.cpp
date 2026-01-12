#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Room;
    int R = N;
    cin >> N;
    if(N == 1) {cout << 1;}
    else {
        for(int i=1; i<R; i++){
            N -= 6*i;
            if(N < 2) {
                Room = i+1;
                break;
            }
        }
        cout << Room;
    }
    return 0;
}