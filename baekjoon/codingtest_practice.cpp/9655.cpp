#include <iostream>
using namespace std;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int s;
    cin >> s;
    if(s%2==0){cout << "CY" << '\n';}
    else {cout << "SK" << '\n';}
    return 0;
}