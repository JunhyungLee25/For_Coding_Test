#include<iostream>
using namespace std;

int main(){
    int S1,S2,S3;
    cin >> S1 >> S2 >> S3;
    int Total[81] = {0};
    for(int i=1; i<=S1; i++){
        for(int j=1; j<=S2; j++){
            for(int k=1; k<=S3; k++){
                Total[i+j+k]++;
            }
        }
    }
    int Max = 0;
    for(int i=3; i<=S1+S2+S3; i++){
        if(Max < Total[i]){
            Max = i;
        }
    }
    cout << Max;
}