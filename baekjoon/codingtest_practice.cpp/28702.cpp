#include<iostream>
#include<string>
using namespace std;

int main(){
    string F;
    int N;
    for(int i=3; i>0; i--){
        cin >> F;
        if(F != "Fizz" && F != "Buzz" && F != "FizzBuzz"){
            N = stoi(F);
            N += i;
        }
    }
    if(N % 15 == 0){
        cout << "FizzBuzz";
    }
    else if(N % 3 == 0){
        cout << "Fizz";
    }
    else if(N % 5 == 0){
        cout << "Buzz";
    }
    else {
        cout << N;
    }
}