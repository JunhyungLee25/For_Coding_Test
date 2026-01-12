#include<iostream>
using namespace std;

int main(){
    int H, M;
    cin >> H >> M;
    if(M<45){
        M = 15 + M;
        if(H>0){
            H--;
        }
        else {
            H = 23;
        }
    }
    else {
        M = M - 45;
    }
    cout << H << M;
}