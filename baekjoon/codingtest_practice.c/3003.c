#include<stdio.h>
int main(){
    int piece[6]={1, 1, 2, 2 ,2 ,8};
    int a=0;
    for(int i=0; i<6; i++){
        scanf("%d",&a);
        printf("%d ",piece[i]-a);
    }
    return 0;
}