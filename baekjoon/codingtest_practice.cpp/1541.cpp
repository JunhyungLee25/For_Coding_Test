#include<iostream>
#include<string>
#include<vector>
using namespace std;

string expression;
int tot;
int num;
string str_num = "";
bool meet_minus = false;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> expression;

    for(int i=0; i<=expression.length(); i++){
        if(expression[i] == '+' || expression[i] == '-' || i == expression.length()){
            int num = stoi(str_num);
            if(meet_minus) tot -= num;
            else tot += num;
            if(expression[i] == '-'){meet_minus = true;}
            str_num="";
        }
        else{
            str_num += expression[i];
        }
    }
    cout << tot;
    return 0;
}