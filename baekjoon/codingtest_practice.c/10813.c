#include<stdio.h>
int main(){
    int N,M,a,b;
    scanf("%d %d",&N,&M);
    int s[100] = {0};
    for(int i=1; i<=N; i++){
        s[i] = i;
    }
    for(int i=0; i<M; i++){
        int temp = 0;
        scanf("%d %d",&a,&b);
        temp = s[a];
        s[a] = s[b];
        s[b] = temp;
    }
    for(int i=1; i<=N; i++){
        printf("%d ",s[i]);
    }
}