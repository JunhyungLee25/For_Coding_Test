#include<iostream>
#include<queue>
using namespace std;
int N;
queue<int> num;
void CARD(){
    while(!num.empty()){
        // 1. top을 버린다.
        int a = num.front();
        num.pop();
        cout << a << ' ';
        if(!num.empty()){
            // 2. top을 맨 뒤로
            a = num.front();
            num.pop();
            num.push(a);
        }
    }
}
int main(void){
    cin >> N;
    for(int i=1; i<=N; i++){
        num.push(i);
    }
    CARD();
    return 0;
}