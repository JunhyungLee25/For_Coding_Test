#include<iostream>
using namespace std;

int main(){ // 12 24 2468 246810121416 2468
    int N;
    cin >> N;
    if(N == 1){
        cout << 1;
        return 0;
    }
    int square = 2;
    while(N-square>0){
        square *= 2;
    }
    int value1 = square-N;
    cout << square-value1*2 ;
}

// gpt가 짠거 N보다 크지 않은 2의 제곱수를 뺀 값에 2를 곱한다. -> 이게 더 간단하긴 하다
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int power = 1;
    while (power * 2 <= N) {
        power *= 2;
    }

    cout << (N - power) * 2;
    return 0;
}
