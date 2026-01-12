#include <stdio.h>
int main(void){
    long long n;
    scanf("%lld",&n);
    long long result = n*(n+1); 
    printf("%lld\n",result/2);
    return 0;
}