#include<stdio.h>
int main(){
    int N,M,a,b;
    scanf("%d %d",&N,&M);
    int s[101] = {0};
    for(int i=1; i<=N; i++){
        s[i]=i;
    }
    for(int i=0; i<M; i++){
        scanf("%d %d",&a,&b);
        int c = b-a+1;
        for(int j=0; j<c/2; j++){
            int temp = 0;
            temp = s[a];
            s[a] = s[b];
            s[b] = temp;
            a++;
            b--;
        }
    }
    for(int i=1; i<=N; i++){
        printf("%d ",s[i]);
    }
    return 0;
}