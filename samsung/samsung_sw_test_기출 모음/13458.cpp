#include<iostream>
#include<vector>
using namespace std;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<long long> A(n);
    int B[2]={0};
    long long total = n;
    for(int i=0; i<n; i++){cin >> A[i];}
    for(int i=0; i<2; i++){cin >> B[i];}
    for(int i=0; i<n; i++){
        if(A[i]-B[0]>0){
            A[i] -= B[0];
            if(A[i]%B[1]==0){A[i] /= B[1];}
            else{A[i] /= B[1]; A[i]++;}
            total += A[i];
        }
    }
    cout << total;
    return 0;
}