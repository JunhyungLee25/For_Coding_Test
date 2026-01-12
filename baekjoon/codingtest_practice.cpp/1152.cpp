#include<iostream>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    int a = s.length();
    int n = 0;
    for(int i=0; i<a-1; i++){
        if(s[i]==' '){
            n++;
        }
    }
    if(s[a-1] != ' '){
        n++;
    }
    cout << n;
}
// 방법 2
#include<iostream>
#include <string>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    int a = s.length();
    int n = 1;
    if (s.length() == 1 && s[0] == ' ') {
		cout << 0;
		return 0;
	}
    for(int i = 1; i<a-1; i++){
        if(s[i] == ' '){
            n++;
        }
    }
    cout << n;
}