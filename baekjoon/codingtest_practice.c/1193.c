#include <stdio.h>
#define max 10000000
int main(void){
    int n;
    scanf("%d",&n);

    int cnt=0;
    for(int i=2; i<max; i++){
        for(int j=1; j<i; j++){
            int k = i-j;
            cnt++;
            int oe = i%2;
            if(cnt==n && oe==1){
                printf("%d/%d\n",j,k);
                return 0;
            }
            else if(cnt==n && oe==0){
                printf("%d/%d\n",k,j);
                return 0;
            }
        }
    }
    return 0;
}