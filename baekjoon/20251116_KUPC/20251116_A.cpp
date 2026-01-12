#include <iostream>
using namespace std;
int main(void){
    int x1,y1,N,x,y;
    cin >> x1 >> y1 >> N;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        if(x==x1 || y==y1){
            cout << 0 << '\n';
        }
        else {
            cout << 1 << '\n';
        }
    }
    return 0;
}