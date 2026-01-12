#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int ZeroCount = N/125 + N/25 + N/5;
    cout << ZeroCount;
}