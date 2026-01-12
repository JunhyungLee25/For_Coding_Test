#include<stdio.h>
int main(void){
    int N;
    long long P = 1;
    scanf("%d", &N);
    if(N==0){
        printf("1");
        return 0;
    }
    while(N>0) {
        P *= N;
        N--;
    }
    printf("%lld", P);
    return 0;
}   