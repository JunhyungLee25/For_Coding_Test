#include<iostream>
using namespace std;
int dp[10001];
int main(void){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t,n;
    cin >> t;
    dp[0]=1;
    for(int i=1; i<=10000; i++){
        dp[i]+=dp[i-1];
    }
    for(int i=2; i<=10000; i++){
        dp[i]+=dp[i-2];
    }
    for(int i=3; i<=10000; i++){
        dp[i]+=dp[i-3];
    }
    while(t--){
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}