#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,k;
    cin >> t;
    while(t--){
        string s;
        cin >> s >> k;
        vector<int> alphabet[26];
        int s_len = s.length();
        for(int i=0; i<s_len; i++){
            int s_idx = s[i]-'a';
            alphabet[s_idx].push_back(i);
        }
        int min_result = 10001;
        int max_result = -1;
        for(int i=0; i<26; i++){
            if(alphabet[i].size() >= k){
                for(int j=0; j<alphabet[i].size(); j++){
                    if(j+k-1 < alphabet[i].size()){
                        min_result = min(alphabet[i][j+k-1] - alphabet[i][j]+1,min_result);
                        max_result = max(alphabet[i][j+k-1] - alphabet[i][j]+1,max_result);
                    }
                }
            }
        }
        if(max_result==-1){cout << -1 << '\n';}
        else{cout << min_result << ' ' << max_result << '\n';}
    }
    return 0;
}