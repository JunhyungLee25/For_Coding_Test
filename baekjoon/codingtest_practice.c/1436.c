#include<stdio.h>
int main(void){
    int N,cnt=1, num,i,check;
    scanf("%d", &N);
    if(N==1){
        printf("666\n");
        return 0;
    }
    for(i=667;; i++){
        num = i;
        check = 0;
        while(num){
            if(num % 1000 == 666){
                check = 1;
            }
            num /= 10;
        
            if(check){
                cnt++;
                if(cnt == N){
                    break;
                }
            }
    }
}
    printf("%d\n", i);
    return 0;
}