#include<iostream>
#include<cmath>
using namespace std;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int result=0;
    int x[n],y[n];
    for(int i=0; i<n; i++){cin >> x[i] >> y[i];}
    for(int i=0; i<n-1; i++){result += abs(x[i+1]-x[i])+abs(y[i+1]-y[i]);}
    int marathon=result;
    for(int i=0; i<n-2; i++){
        int min=result;
        
        min -= abs(x[i+1]-x[i])+abs(y[i+1]-y[i]);
        min -= abs(x[i+2]-x[i+1])+abs(y[i+2]-y[i+1]);
        min += abs(x[i+2]-x[i])+abs(y[i+2]-y[i]);
        
        if(marathon>min){marathon=min;}
    }
    cout << marathon;
    return 0;
}