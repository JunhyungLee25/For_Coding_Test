#include <iostream>
using namespace std;

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,car=0;
    cin >> t;
    for(int i=0; i<t; i++){
        int op,a,b;
        cin >> car >> a;
        for(int j=0; j<a; j++){
            cin >> b >> op;
            car += b*op;
        }
        cout << car << '\n';
    }
    return 0;
}