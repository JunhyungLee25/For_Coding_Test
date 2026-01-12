#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> m(N);
    for(int i=0; i<N; i++){
        cin >> m[i]; 
    }
    sort(m.begin(),m.end());

    for(int i=0; i<N; i++){
        cout << m[i] <<'\n';
    }
}