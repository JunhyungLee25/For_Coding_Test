#include<iostream>
using namespace std;

int main(){
    int V,A,B;
    cin >> A >> B >> V;

    int Day = 0;
    int Height  = 0;

    while(1){
        Height += A;
        Day++;
        if(Height >= V){
            cout << Day;
            break;
            }
        Height -= B;
    }
}