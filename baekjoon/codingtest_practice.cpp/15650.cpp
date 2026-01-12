#include<iostream>
using namespace std;
int n,m;
int arr[9];
void dfs(int s,int cnt){
    if(cnt == m){
        for(int i=0; i<m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=s; i<=n; i++){
        arr[cnt]=i;
        dfs(i+1,cnt+1);
    }
}
int main(void){
    cin >> n >> m;
    dfs(1,0);
    return 0;
}