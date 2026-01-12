#include<iostream>
using namespace std;
int main(void){
    int n,m,x_1;
    int x[100001];
    cin >> n >> m;
    if(m==1){
        cin >> x_1;
        if(x_1*2>n){cout << x_1;}
        else{cout << n-x_1;}
    } else{
        cin >> x[0];
        int result=x[0];
        for(int i=1; i<m; i++){
           cin >> x[i];
            if(result < (x[i]-x[i-1]+1)/2 ){result=(x[i]-x[i-1]+1)/2;}
        }
        if(result<(n-x[m-1])){
            result = n-x[m-1];
        }
        cout << result;
    }
    return 0;
}