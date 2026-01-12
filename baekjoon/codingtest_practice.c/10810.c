#include<stdio.h>
int main(){
    int N,M,a,b,c;
    int s[100] = {0};
    scanf("%d %d",&N,&M);
    for(int i=0; i<M; i++){
        scanf("%d %d %d",&a,&b,&c);
        for(int j=a; j<=b; j++){
            s[j] = c;
        }
    }
    for(int i=1; i<=N; i++){
        printf("%d ",s[i]);
    }
    return 0;
}