#include <iostream>
using namespace std;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    int n;
    cin >>n;
    int d0 = 1;
    int d1 = 3;
    int result = 5;
    if(n==1){cout << 1 << '\n'; return 0;}
    else if(n==2){cout << 3 << '\n'; return 0;}
    else{
        for(int i=3; i<=n; i++){
            result = (d1 + (d0*2)%10007)%10007;
            d0 = d1;
            d1 = result;
        }
        cout << result << '\n';
    }
    return 0;
}