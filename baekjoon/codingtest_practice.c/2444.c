#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    for(int i=N; i>0; i--){
        for(int k=i; k>1; k--){
            printf(" ");
        }
        for(int j=0; j<=2*N-2*i; j++){
            printf("*");
        }
        printf("\n");
    }
    for(int i=1; i<N; i++){
        for(int k=N; k>N-i; k--){
            printf(" ");
        }
        for(int j=1; j<2*N-2*i; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}