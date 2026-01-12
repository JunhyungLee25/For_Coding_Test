#include<stdio.h>
#include<stdlib.h>

int *p;
int compare(const void *a, const void *b){
    return (*(int*)a-*(int*)b);
}

void minimum_sum(int *p, int n){
    qsort(p,n,sizeof(int),compare);
    for(int i=1; i<n; i++){
        p[i] += p[i-1];
    }
}

int main(void){
    int i,N;
    scanf("%d",&N);
    p=(int *)malloc(N*sizeof(int));
    for(i=0; i<N; i++){
        scanf("%d",&p[i]);
    }
    minimum_sum(p,N);
    int min_total=0;
    for(i=0; i<N; i++){
        min_total += p[i]; 
    }
    printf("%d\n",min_total);
    return 0;
}