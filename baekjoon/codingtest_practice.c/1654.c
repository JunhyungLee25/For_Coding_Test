#include <stdio.h>
int main(void){
    int n,k;
    scanf("%d %d",&n,&k);
    long long lan[10001]={0,};
    long long max_lan=0;
    for(int i=0; i<n; i++){
        scanf("%lld",&lan[i]);
        if(max_lan<lan[i]){
            max_lan=lan[i];
        }
    }
    long long left=1,right=max_lan,result=0;
    while(left<=right){
        long long mid = (left+right)/2;
        int cnt=0;
        for(int i=0; i<n; i++){
           cnt+=lan[i]/mid;
        }
        if(k<=cnt){
            if(result<mid){
                result=mid;
            }
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    printf("%lld\n",result);
    return 0;
}