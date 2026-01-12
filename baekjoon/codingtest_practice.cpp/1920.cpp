#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool checkarray(const vector<int> &arr, int a){
    int left = 0, right = arr.size()-1;
    while(left <= right){
        int middle = left+(right-left)/2;
        if(a == arr[middle]){
            return true;
        } else if(a > arr[middle]){
            left = middle + 1;
        } else{
            right = middle -1;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int N,M;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    cin >> M;
    for(int i=0; i<M; i++){
        int B = 0;
        cin >> B;
        if(checkarray(A ,B)){
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
    return 0;
}