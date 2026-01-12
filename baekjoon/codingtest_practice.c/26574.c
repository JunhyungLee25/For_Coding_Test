#include<stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int k;
        scanf("%d",&k);
        printf("%d %d\n",k,k);
    }
    return 0;
}