#include<iostream>
using namespace std;
char words[5][16];
int main(void){
    for(int i=0; i<5; i++){
        cin >> words[i];
    }
    for(int i=0; i<15; i++){
        for(int j=0; j<5; j++){
            if(words[j][i] == '\0') continue;
            cout << words[j][i];
        }
    }
    return 0;
}

/*
1. 문자열이 저장될 때는 마지막에 '\0'문자가 붙는데 처음에 배열 선언을 words[5][15]로 해서 overflow가 발생하였다.
2. 출력하지 않는 조건을 단순히 0으로만 해서 문제가 생겼다. 정확하게 '\0'으로 해야한다.
*/