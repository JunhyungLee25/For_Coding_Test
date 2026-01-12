#include<iostream>
using namespace std;

int main(){
    int N1;
    string N2;
    cin >> N1 >> N2;
    cout << N1*(N2[2]-'0') << '\n';
    cout << N1*(N2[1]-'0') << '\n';
    cout << N1*(N2[0]-'0') << '\n';
    cout << N1*(N2[2]+N2[1]*10+N2[0]*100);
}