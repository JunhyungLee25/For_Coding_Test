#include<stdio.h>
int main(void){
    int n1,n2;
    while(1){
        scanf("%d %d",&n1,&n2);
        if(n1==0 && n2==0){return 0;}
        printf("%s", (n1 > n2 ? "Yes\n" : "No\n"));
    }
}