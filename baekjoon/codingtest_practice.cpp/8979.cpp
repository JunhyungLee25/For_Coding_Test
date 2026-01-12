#include <iostream>
#include <vector>
using namespace std;
typedef struct MEDAL{
    int gold;
    int silver;
    int bronze;
}MD;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<MD> medals(n);
    int a,g,s,b;
    for(int i=0; i<n; i++){
        cin >> a >> medals[i].gold >> medals[i].silver >> medals[i].bronze;
        if(a==k){
            g=medals[i].gold; s = medals[i].silver; b=medals[i].bronze;
        }
    }
    int d=1;
    for(int i=0; i<n; i++){
        if(medals[i].gold > g){
            d++;
        }
        else if(medals[i].gold == g && medals[i].silver > s){
            d++;
        }
        else if(medals[i].gold == g && medals[i].silver == s && medals[i].bronze > b){
            d++;
        } 
    }
    cout << d << '\n';
    return 0;
}