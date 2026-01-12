#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000000

typedef struct {
    int value;
    int index;
    int rank;
} num;

int *x;
int com[SIZE];

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void x_compression(int *x,int n){
    int i;
    num *t=(num *)malloc(n*sizeof(num));
    for(i=0; i<n; i++){
        t[i].value = x[i];
        t[i].index=i;
    }
    qsort(t,n,sizeof(num),compare);
    int rank=0;
    t[0].rank=0;
    for(i=1; i<n; i++){
        if(t[i].value==t[i-1].value){
            t[i].rank=rank;
        }
        else{
            t[i].rank=++rank;
        }
    }
    for(i=0; i<n; i++){
        x[t[i].index]=t[i].rank;
    }
    free(t);
}


int main(void){
    int i,N;
    scanf("%d",&N);
    x = (int *)calloc(N,sizeof(int));
    
    for(i=0; i<N; i++){
        scanf("%d",&x[i]);
    }
    x_compression(x,N);
    for(i=0; i<N; i++){
        printf("%d ",x[i]);
    }
    free(x);
    return 0;
}