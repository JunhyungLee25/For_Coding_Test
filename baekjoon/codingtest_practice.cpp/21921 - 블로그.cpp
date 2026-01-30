#include<iostream>
using namespace std;
int visit[250001];
long long max_visit;
int max_visit_cnt=1;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,x;
    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> visit[i];
    }
    long long sum = 0;
    for(int i=0; i<x; i++){
        sum += visit[i];
    }
    max_visit = sum;
    for(int i=0; i+x<n; i++){
        sum = sum - visit[i] + visit[i+x];
        if(max_visit < sum){
            max_visit = sum;
            max_visit_cnt=1;
        } else if(max_visit == sum){
            max_visit_cnt++;
        }
    }
    if(max_visit==0){cout << "SAD";}
    else cout << max_visit << '\n' << max_visit_cnt;

    return 0;
}