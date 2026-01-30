#include<iostream>
#include<string>
using namespace std;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string number;
    cin >> number;
    int base = 0;
    int pointer = 0;
    while(pointer < number.length()){
        base++;
        string target = to_string(base);
        for(int i=0; i<target.length(); i++){
            if(target[i] == number[pointer]){
                pointer++;
                if(pointer >= number.length()) break;
            }
        }
    }
    cout << base;
    return 0;
}