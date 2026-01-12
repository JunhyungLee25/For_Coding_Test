#include <iostream>
using namespace std;
int s[50001];
int min(int q,int w){return q<w ? q : w;}
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    int x;
    cin >> x;
    for(int n=1; n<=x; n++){
        s[n] = s[n-1]+1;
        for(int i=2; i*i<=n; i++){
            int y=s[n-i*i]+1;
            s[n] = min(s[n],y);
        }
    }
    cout << s[x] << '\n';
    return 0;
}