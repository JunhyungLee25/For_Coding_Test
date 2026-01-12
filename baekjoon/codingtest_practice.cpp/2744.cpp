#include<iostream>
using namespace std;

int main(){
    string A;
    cin >> A;
    for(int i=0; i< A.length(); i++){
        char c = A[i];
        if('a' <= c && c <= 'z'){
            A[i] = A[i] - 32;
        }
        else  {
            A[i] = A[i] + 32;
        }
    }
    cout << A;
}