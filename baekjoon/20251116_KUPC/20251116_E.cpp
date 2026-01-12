#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int d,e,s,k;
    bool t=true;
    cin >> d >> e >> s;
    vector<int> a(d+e+s);
    a.clear();
    for(int i=1; i<=s; i++){
        cin >> k;
        a[k] = 1; 
    }
    if(a[1] && (d-e)==1){
        cout << "NO" << '\n';
        return 0;
    }
    for(int i=2; i<=d; i++){
        if(a[i]==0 && t){
            t=false;
            if((i+e)>d){
                for(int j=1; (i+j)==d; j++){
                    if(a[i+j]){
                        cout << "NO" << '\n';
                        return 0;        
                    }
                }
            }
            else {
                for(int j=1; j<=e; j++){
                    if(a[i+j]){
                        cout << "NO" << '\n';
                        return 0;        
                    }
                }
            }
            if(a[i]){
                t=true;
            }
        }
    }
    cout << "YES" << '\n';
    return 0;
}