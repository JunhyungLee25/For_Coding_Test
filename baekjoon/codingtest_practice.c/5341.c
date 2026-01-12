#include<stdio.h>
int main(void){
    while(1){
        int n,k=0;
        scanf("%d",&n);
        if(n==0){return 0;}
        for(int i=1; i<=n; i++){
            k += i;
        }
        printf("%d\n",k);
    }
    return 0;
}