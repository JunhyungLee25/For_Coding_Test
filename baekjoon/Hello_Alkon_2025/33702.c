#include <stdio.h>
int main(void){
    int K;
    scanf("%d",&K);
    if(K==1||K==3||K==5||K==7||K==9){
        printf("8\n");
    }
    else{
        printf("0\n");
    }
    return 0;
}