#include<iostream>
#include<string>
#include<stack>
using namespace std;
 
stack<int> s;
void DoOrder(string a, int b = 0){
    if(a == "push"){
        s.push(b);
    }
    else if(a == "pop" ){
        if(!s.empty()){
            cout << s.top() << '\n';
            s.pop();
        } else {
            cout << -1 << '\n';
        }
    }
    else if(a == "size"){
        cout << s.size() << '\n';
    }
    else if(a == "empty"){
        cout << s.empty() << '\n';
    }
    else if(a == "top"){
        if(!s.empty()){
            cout << s.top() << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N,num;
    cin >> N;
    string order;
    for(int i=0; i<N; i++){
        cin >> order;
        if(order == "push"){
            cin >> num;
            DoOrder(order, num);
        } else {
            DoOrder(order);}
    }
    return 0;
}