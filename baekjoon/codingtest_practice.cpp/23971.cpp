#include <iostream>
using namespace std;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h,w,n,m;
    int y,x;
    cin >> h >> w >> n >> m;
    if(h%(1+n)==0){
        y = h/(1+n);
    }
    else{
        y = h/(1+n)+1;
    }
    if(w%(1+m)==0){
        x = w/(1+m);
    }
    else{
        x = w/(1+m)+1;
    }
    cout << x*y << '\n';
    return 0;
}