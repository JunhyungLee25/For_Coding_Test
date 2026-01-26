#include<iostream>
#include<algorithm>
bool compare(int a, int b) {return a>b;}
using namespace std;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n;
    int money[10001];
    int total=0;
    int max=0;
    for(int i=0; i<n; i++){
        cin >> money[i];
        total += money[i];
        if(max < money[i]){max = money[i];}
    }
    cin >> m;
    int diff = m-total;
    if(diff>0){cout << max;}
    else {
        sort(money,money+n,compare);
        int low = 0;
        int high = max;
        int limit;
        while(low<=high){
            int mid = (low+high)/2;
            long long cur_total = 0;
            for(int i=0; i<n; i++){
                cur_total += min(money[i],mid);
            }
            if(cur_total<=m){
                limit = mid;
                low = mid+1;
            }
            else {high = mid-1;}
        }
        cout << limit;
    }
    return 0;
}