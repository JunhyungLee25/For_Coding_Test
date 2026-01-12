#include <stdio.h>
int main(void){
    int n;
    long p[100]={1,1,1,};;
    scanf("%d",&n);
    for(int i=3; i<100; i++){
        p[i] = p[i-2]+p[i-3];
    }
    for(int i=0; i<n; i++){
        int idx;
        scanf("%d",&idx);
        printf("%ld\n",p[idx-1]);
    }
    return 0;
}