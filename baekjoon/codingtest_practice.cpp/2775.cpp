// #include<iostream>
// #include<vector>
// using namespace std;

// int main(){
//     // int R[5] = {1,2,3,4,5};  // 0 1 2 3 4
//     int k;
//     int a,b;
//     cin >> a >> b; // 3 5
//     vector<int> R(b);
//     for(int r=0; r<b; r++){
//         R[r] = r+1;
//     }
//     for(int i=0; i<a; i++){
//         for(int j=b-1; j>0; j--){ // b=5면 j는 4부터 시작
//             for(int k=j-1; k>=0; k--){
//                 R[j] += R[k];
//             }
//         }
//     }
//     for(int q=0; q<b; q++){
//         cout << R[q] << '\n';
//     }
//     return 0;
// }
#include<iostream>
#include<vector>
using namespace std;

int Resident(int k, int n){
    vector<int> R(n);
    for(int r=0; r<n; r++){
        R[r] = r+1;
    }
    for(int f=0; f<k; f++){
        for(int j=n-1; j>0; j--){\
            for(int m=j-1; m>=0; m--){
                R[j] += R[m]; 
            }
        }
    }
    return R[n-1];
}

int main(){
    int T,k,n;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> k >> n;
        cout << Resident(k, n) << '\n';
    }
    return 0;
}