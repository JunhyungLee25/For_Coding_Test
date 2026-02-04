#include<iostream>
#include<stack>
using namespace std;
stack<pair<int, int>> possible_top;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,height;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> height;
        while(!possible_top.empty() && possible_top.top().first < height) {possible_top.pop();}
        if(possible_top.empty()) cout << 0 << ' ';
        else cout << possible_top.top().second << ' ';
        possible_top.push({height,i+1});
    }
    return 0;
}