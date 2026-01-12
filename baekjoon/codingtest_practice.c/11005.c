#include<stdio.h>
int main(void){
    int N,B;
    scanf("%d %d", &N,&B);
    char output[10001];
    int i=0;
    while(N > 0){
        int num = N % B; 
        if(num>=10){output[i] = 'A'+ (num-10);}
        else{output[i] = num + '0';}
        N /= B;
        i++;
    }
    for(int j=i-1; j>=0; j--){
        printf("%c",output[j]);
    }
    return 0;
}