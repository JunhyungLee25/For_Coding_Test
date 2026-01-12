#include<iostream>
using namespace std;

int main(){
    // 7<=h<=22, 0<=m<=59, 0<=s<=59
    int H = 0,M = 0,S = 0;
    int h[10],m[10],s[10];
    for(int i=0; i<5; i = i+2){
        cin >> h[i] >> m[i] >> s[i] >> h[i+1] >> m[i+1] >> s[i+1];
    }
    for(int j=0; j<5; j = j+2){
        if(s[j+1]-s[j] < 0){
            S = 60+s[j+1]-s[j];
            if(m[j+1]-m[j] <= 0){
                M = 60+m[j+1]-m[j]-1;
                H = h[j+1]-h[j]-1;
            }
            else {
                M = m[j+1]-m[j]-1;
                H = h[j+1]-h[j];
            }
        }
        else{
            S = s[j+1]-s[j];
            if(m[j+1]-m[j] < 0){
                M = 60+m[j+1]-m[j];
                H = h[j+1]-h[j]-1;
            }
            else {
                H = h[j+1]-h[j];
            }
        }
        cout << H << " " << M << " " << S <<'\n';
    }
}