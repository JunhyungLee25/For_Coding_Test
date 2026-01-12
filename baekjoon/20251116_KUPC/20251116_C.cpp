#include <iostream>
using namespace std;
int main(void){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int c,max=0;
    for(int i=0; i<14; i++){
        cin >> c;
        if(max < c){
            max = c;
        }
    }
    cin >> c;
    if(max < c){
        cout << c << '\n';
    }
    else {
        cout << max+1 << '\n';
    }
}