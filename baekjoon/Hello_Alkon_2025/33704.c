#include <stdio.h>
int main(void){
    int N;
    scanf("%d",&N);
    int A[2]={0,0};
    if(N>2){
        printf("YES\n");
        return 0;
    }
    else{
        scanf("%d",&A[0]);
        scanf("%d",&A[1]);
        if(A[0]<= A[1]){
            printf("YES\n");
            return 0;
        }
        else {
            printf("NO\n");
            return 0;
        }
    }
    return 0;
}