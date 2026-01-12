#include <stdio.h>
int acc_sum[100001];
int main(void){
    int n,m,num;
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++){
        scanf("%d",&num);
        acc_sum[i+1]=acc_sum[i]+num;
    }
    for(int i=0; i<m; i++){
        int s,e,sum;
        scanf("%d %d",&s,&e);
        sum = acc_sum[e]-acc_sum[s-1];
        printf("%d\n",sum);
    }
    return 0;
}