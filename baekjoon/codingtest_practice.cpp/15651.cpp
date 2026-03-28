#include<iostream>
using namespace std;
int N,M;
int num[8];

void DFS(int cnt){
    if(cnt==M){
        for(int i=0; i<M; i++){
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1; i<=N; i++){
        num[cnt] = i;
        DFS(cnt+1);
    }
}

int main(void){
    cin >> N >> M;
    DFS(0);
    return 0;
}