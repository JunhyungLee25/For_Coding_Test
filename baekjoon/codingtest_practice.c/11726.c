#include <stdio.h>
int rect[1001]={1,2,};
int main(void){
    int n;
    scanf("%d",&n);
    if(n==1){printf("1\n");}
    else if(n==2){printf("2\n");}
    else{
        for(int i=3; i<=n; i++){
            rect[i-1] = (rect[i-2] + rect[i-3])%10007;
        }
        printf("%d\n",rect[n-1]);
    }
    return 0;
}