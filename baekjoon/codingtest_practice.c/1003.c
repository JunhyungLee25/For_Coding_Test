#include <stdio.h>
int zero[41]={1,0,};
int one[41]={0,1,};
void count_z_o(int num){
    int count = 2;
    while(count<=num){
        zero[count] = zero[count-1]+zero[count-2];
        one[count] = one[count-1]+one[count-2];
        count++;
    }
}
int main(void){
    int t,n;
    scanf("%d",&t);
    count_z_o(40);
    for(int i=0; i<t; i++){
        scanf("%d",&n);
        printf("%d %d\n",zero[n],one[n]);
    }
    return 0;
}