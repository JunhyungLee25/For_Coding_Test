#include<iostream>
using namespace std;

int main(){
    long long A,B;
    cin >> A >> B;
    long long q = A/B;
    long long r = A%B;
    if(r < 0) { // r의 부호 == A의 부호
        r += abs(B);
        q += (B < 0) ? 1 : -1;  
    }
    cout << q << '\n' << r;
    // cout << 7/-3 <<'\n';
    // cout << -7/-3<<'\n';
    // cout << 7/3<<'\n';
    // cout << -7/3<<'\n';
}