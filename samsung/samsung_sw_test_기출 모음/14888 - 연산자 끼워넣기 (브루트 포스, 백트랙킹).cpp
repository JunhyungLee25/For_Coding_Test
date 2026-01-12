#include<iostream>
using namespace std;
int num[11];
int max_result=-1000000001;
int min_result=1000000001;
void max_min_calc(int temp, int plus, int minus, int mul, int div, int index){
    if(plus==0 && minus==0 && mul==0 && div==0){
        if(temp > max_result){max_result = temp;}
        if(temp < min_result){min_result = temp;}
        return;
    }
    if(plus>0){max_min_calc(temp+num[index], plus-1, minus, mul, div, index+1);}
    if(minus>0){max_min_calc(temp-num[index], plus, minus-1, mul, div, index+1);}
    if(mul>0){max_min_calc(temp*num[index], plus, minus, mul-1, div, index+1);}
    if(div>0){max_min_calc(temp/num[index], plus, minus, mul, div-1, index+1);}
    return;
}
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,plus,minus,mul,div;
    cin >> n;
    for(int i=0; i<n; i++){cin >> num[i];} 
    cin >> plus >> minus >> mul >> div;
    max_min_calc(num[0],plus,minus,mul,div, 1);
    cout << max_result << '\n' << min_result;
    return 0;
}