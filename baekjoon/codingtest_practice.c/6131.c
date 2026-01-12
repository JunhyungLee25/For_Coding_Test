#include <stdio.h>
int main(void){
    int n,res=0;
    scanf("%d",&n);
    for(int b=1; b<=500; b++){
        for(int a=b; a<=500; a++){
            if((a*a)==(b*b+n)){res++;}
        }
    }
    printf("%d",res);
    return 0;
}