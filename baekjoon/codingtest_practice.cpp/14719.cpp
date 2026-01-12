#include<iostream>
#include<algorithm>
using namespace std;
int h,w;
int x[501];
int find_lmax(int k){
    int max = 0;
    for(int i=0; i<k; i++){
        if(max < x[i]){max=x[i];}
    }
    return max;
}
int find_rmax(int k){
    int max = 0;
    for(int i=k+1; i<w; i++){
        if(max < x[i]){max=x[i];}
    }
    return max;
}
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> h >> w;
    if(w==1 || w==2){cout << 0; return 0;}
    int result=0;
    for(int i=0; i<w; i++){cin >> x[i];}
    for(int i=1; i<w-1; i++){
        int l_max=find_lmax(i); 
        int r_max=find_rmax(i); 
        int standard = min(l_max,r_max);
        if(standard > x[i]){
            result += (standard - x[i]);
        }
    }
    cout << result;
    return 0;
}