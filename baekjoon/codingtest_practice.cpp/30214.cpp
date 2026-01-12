#include<iostream>
using namespace std;

int main(){
    int s1,s2;
    cin >> s1 >> s2;
    if(s2 / s1 <= 2){
        cout << "E";
    }
    else {
        cout << "H";
    }
}