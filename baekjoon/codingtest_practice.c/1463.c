#include <stdio.h>
#include <stdlib.h>
int min(const int a, const int b){return a < b ? a : b;}
int main(void){
    int n;
    scanf("%d", &n);
    int* num = (int*)malloc((n+1)*sizeof(int));
    num[1] = 0;
    for(int i=2; i<n+1; i++){
        num[i] = num[i-1]+1;
        if(i%2==0){num[i] = min(num[i], num[i/2]+1);}
        if(i%3 == 0){num[i] = min(num[i], num[i/3]+1);}
    }
    printf("%d",num[n]);
    free(num);
    return 0;
}