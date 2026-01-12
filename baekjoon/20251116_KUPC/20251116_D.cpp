#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> A(n), B(2*n);
    for(int i=0;i<n;i++) {
        cin >> A[i];
    }
    for(int i=0;i<2*n;i++) {
        cin >> B[i];
    }

    for(int i=0;i<n;i++){
        if(A[i] != B[i]){ 
            cout << "NO\n"; 
            return 0; 
        }
    }

    // 존재 여부 체크 (값 범위 1..N)
    vector<char> exists(n+1, false);
    for(int x : A) if(x>=1 && x<=n) exists[x] = true;

    for(int i=n;i<2*n;i++){
        int v = B[i];
        if(v < 1 || v > n || !exists[v]){ cout << "NO\n"; return 0; }
        exists[v] = true; // 이미 true, 명시적으로 유지
    }

    cout << "YES\n";
    return 0;
}