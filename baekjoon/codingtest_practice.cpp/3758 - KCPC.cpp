#include<iostream>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,k,mt,m;
        int ti,pi,s;
        cin >> n >> k >> mt >> m;
        int score[101][101] = {0};
        int count[101] = {0};
        int last_time[101] = {0};
        for(int i=0; i<m; i++){
            cin >> ti >> pi >> s;
            if(score[ti][pi]<s){
                score[ti][0] += (s-score[ti][pi]);
                score[ti][pi] = s;
            }
            count[ti]++;
            last_time[ti] = i;
        }
        int ms = score[mt][0];
        int mr = 1;
        for(int i=1; i<=n; i++){
            if(mt == i) {continue;}
            if(ms < score[i][0]) {mr++;}
            else if(ms == score[i][0]){
                if(count[mt] > count[i]) {mr++;}
                else if(count[mt] == count[i]){
                    if(last_time[mt] > last_time[i]) {mr++;}
                } 
            }
        }
        cout << mr << '\n';
    }
    return 0;
}