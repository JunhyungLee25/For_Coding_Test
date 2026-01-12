#include <iostream>
using namespace std;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int p;
    cin >> p;
    int child[20]={0,};
    for(int i=0; i<p; i++){
        int cnt=0;
        int t;
        cin >> t;
        for(int j=0; j<20; j++){
            cin >> child[j];
            for(int k=0; k<j; k++){
                if(child[k] > child[j]){
                    cnt += (j-k);
                    int a = child[j];
                    for(int s=0; s<j-k; s++){
                        child[j-s]=child[j-s-1];
                    }
                    child[k]=a;
                    break;
                }
            }
        }
        cout << t << ' ' << cnt << '\n';
    }
    return 0;
}