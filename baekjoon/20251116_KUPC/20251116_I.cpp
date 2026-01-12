#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t,d,k;
    cin >> t;
    while(t--){
        cin >> d >> k;
        string a;
        cin >> a;
        vector<int> result;
        int idx=0;
        for(int i=1; i<=d; i++){
            if((a[d-i]-'0')!=0 && (a[d-i]-'0')!=1){
                idx = d-i;
                break;
            }
        }
        for(int i=0; i<=idx; i++){
            result.push_back(a[i]-'0');
        }
        int idx1=idx;
        for(int i=0; i<k; i++){
            if(idx >= result.size()) {
                break;
            }
            int b;
            if(2 <= (result[idx]) && (result[idx])  <= 8){
                b = result[idx] * 9;
                result[idx] = (b / 10);
                result.insert(result.begin() + idx + 1,b % 10);
                idx++;
            }
            else if((result[idx])==9){
                result[idx] = 8;
                result.push_back(1);
            }
            else {
                result[idx] = 9;
            }
        }
        for(int i=idx1+1; i<d; i++){
            result.push_back(a[i] - '0');
        }
        for(int i=0; i<result.size(); i++){
            cout << result[i];
        }
        cout << '\n';
    }

    return 0;
}