#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    long long n, m;
    cin >> n >> m;
    cout << n / m << '\n';
    cout << n % m;
}
