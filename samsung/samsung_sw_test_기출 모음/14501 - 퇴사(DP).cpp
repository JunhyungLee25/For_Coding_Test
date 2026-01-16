#include<iostream>
#include<algorithm>
using namespace std;
int day[15];
int wage[15];
int dp[15];
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,result=0;
    cin >> n;
    for(int i=0; i<n; i++){cin >> day[i] >> wage[i];}
    for(int i=0; i<=n; i++){
        dp[i]=max(result, dp[i]);
        if(i+day[i]<=n){
            dp[i+day[i]] = max(dp[i+day[i]], dp[i]+wage[i]);
        }
        result =  max(result,dp[i]);
    }
    cout << result;
    return 0;
}