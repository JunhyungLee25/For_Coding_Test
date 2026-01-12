#include <iostream>
using namespace std;
int n[10][10];
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int max=0,x=1,y=1;
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            cin >> n[i][j];
            if(max < n[i][j]){
                max = n[i][j];
                x=j;
                y=i;
            }
        }
    }
    cout << max << '\n' << y << ' ' << x << '\n';
    return 0;
}