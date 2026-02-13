#include<iostream>
using namespace std;
int words[100][26];
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,result=0;
    cin >> n;
    string wd;
    for(int i=0; i<n; i++){
        cin >> wd;
        for(int j=0; j<wd.size(); j++){
            words[i][wd[j]-'A']++;
        }
    }
    for(int i=1; i<n; i++){
        int p_cnt=0;
        int n_cnt=0;
        for(int j=0; j<26; j++){
            //if(words[0][j]==words[i][j]) continue;
            if(words[0][j]!=words[i][j]){
                if(words[0][j]-words[i][j]>0) p_cnt+=words[0][j]-words[i][j];
                else if(words[0][j]-words[i][j]<0)n_cnt-=words[0][j]-words[i][j]; 
            } 
        }
        if(p_cnt<=1 && n_cnt<=1) result++;
    }
    cout << result;
    return 0;
}