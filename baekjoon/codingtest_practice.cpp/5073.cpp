#include <iostream>
using namespace std;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b,c;
    while(1){
        cin >> a >> b >> c;
        int max = a;
        if(a==0 && b==0 && c==0){
            return 0;
        }
        else if(a==b && b==c){
            cout << "Equilateral" << '\n';
        }
        else if((a>b && a>c && a>=(b+c)) || (b>a && b>c && b>=(a+c)) || (c>a && c>b && c>=(a+b))){
            cout << "Invalid" << '\n';
        }
        else if(a==b || b==c || c==a){
            cout << "Isosceles" << '\n';
        }
        else{
            cout << "Scalene" << '\n';
        }
    }
    return 0;
}