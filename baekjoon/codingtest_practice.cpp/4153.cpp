#include<iostream>
using namespace std;

int main(){
    int A[3];
    int right = 0;
    for(int i=0; i<3; i++){
        cin >> A[i];
    }
    if(A[0]*A[0]+A[1]*A[1] == A[2]*A[2]){
        right++;
    }
    else if(A[0]*A[0]+A[2]*A[2] == A[1]*A[1]){
        right++;
    }
    else if(A[1]*A[1]+A[2]*A[2] == A[0]*A[0]){
        right++;
    }
    if( right == 1){
        cout << "right";
    }
    else { cout << "wrong";}
}