#include <iostream>
using namespace std;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b,c;
    while(1){
        cin >> a >> b >> c;
        if(a==0 && b==0 && c==0){
            return 0;
        }
        int max = a,i=b,j=c;
        if(b>a && b>c){max = b,i=a,j=c;}
        if(c>a && c>b){max = c,i=a,j=b;}
        if(max >=(i+j)){
            cout << "Invalid" << '\n';
        }
        else if(a==b && b==c){
            cout << "Equilateral" << '\n';
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