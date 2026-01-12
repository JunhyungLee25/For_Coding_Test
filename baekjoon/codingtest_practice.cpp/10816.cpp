#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(NULL);
    int N,M;
    cin >> N;
    int Max = 10000001;
    vector<int> PositiveN(Max, 0);
    vector<int> NegativeN(Max, 0);
    int num;
    for(int i=0; i<N; i++){ 
        cin >> num;
        if(num < 0){
            NegativeN[-num]++;
        } else{
            PositiveN[num]++;
        }
    }
    cin >> M;
    int p;
    for(int i=0; i<M; i++){
        cin >> p;
        if(p>=0){
            cout << PositiveN[p] << " ";
        } else {
            cout << NegativeN[-p] << " ";
        }
    }
    return 0;
}