#include<iostream>
using namespace std;
int cnt_p=0;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;;
    cin >> n >> k;
    string input;
    cin >> input;
    int len = input.size();
    for(int i=0; i<len; i++){
        if(input[i]=='P'){
            for(int j=-k; j<=k; j++){
                if(i+j>=0 && input[i+j]=='H'){
                    cnt_p++;
                    input[i+j]='0';
                    break;
                }
            }
        }
    }
    cout << cnt_p;
    return 0;
}