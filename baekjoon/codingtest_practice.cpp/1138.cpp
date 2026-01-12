#include<iostream>
using namespace std;
int people[10];
int result[10];
int main(void){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int cnt=0;
        cin >> people[i];
        for(int j=0; j<n; j++){
            if(result[j]==0){
                if(cnt==people[i]){
                    result[j]=i+1;
                    break;
                }
                cnt++;
            }
        }
    }    
    for(int i=0; i<n; i++){
        cout << result[i] << ' ';
    }
    return 0;
}