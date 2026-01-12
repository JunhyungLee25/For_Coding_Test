#include <iostream>
using namespace std;
int sum(int A,int B){
    cout << A+B << '\n';
    return 0;
}
int main(void){
    int A,B;
    cin >> A >> B;
    sum(A,B);
}