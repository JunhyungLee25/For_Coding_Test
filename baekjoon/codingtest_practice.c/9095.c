#include<stdio.h>
int result[11]={1,2,4,};
int main(void){
    int n,t;
    scanf("%d",&t);
    for(int i=0; i<8; i++){result[3+i] = result[i]+result[i+1]+result[i+2];}
    for(int i=0; i<t; i++){
        scanf("%d",&n);
        printf("%d\n",result[n-1]);
    }
    return 0;
}