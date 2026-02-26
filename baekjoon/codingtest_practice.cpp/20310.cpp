#include<iostream>
using namespace std;
string s1;
int z,o,cnt;
int main(void){
    cin >> s1;
    for(int i=0; i<s1.length(); i++){
        if(s1[i] == '0') z++;
        else if(s1[i] == '1') o++;
    }
    z /= 2;
    o /= 2;
    for(int i=0; i<s1.length(); i++){
        if(cnt==o) break;
        if(s1[i] == '1'){
            s1[i] = 3;
            cnt++;
        }
    }
    cnt=0;
    for(int i=s1.length()-1; i>=0; i--){
        if(cnt==z) break;
        if(s1[i] == '0'){
            s1[i] = 3;
            cnt++;
        }
    }
    for(int i=0; i<s1.length(); i++){
        if(s1[i]==3) continue;
        cout << s1[i];
    }    
    return 0;
}