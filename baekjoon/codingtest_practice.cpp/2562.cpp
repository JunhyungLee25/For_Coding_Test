#include<iostream>
using namespace std;

int main(){
    int s;
    int b;
    int A[100];
    int i,j;
    for(i=0; i<9; i++){
        cin >> A[i];
    }
    for(i=0; i<9; i++){
        if( s == i){
            s = i;
            break;
        }
        else if( s== j){
            s = j;
            break;
        }
        for(j=0; j<9; j++){
            if(A[i] > A[j]){
                b = A[i];
                s = i;
            }
            else if(A[i]<A[j]){
                b = A[j];
                s = j;
            }
        }
    }
    cout << b <<'\n';
    cout << s;
}