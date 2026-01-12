#include <stdio.h>
#include <stdlib.h>
int parti[1001];
int compare(const int *a, const int *b){
    return *a - *b;
}
int main(void){
    int N,prize;
    scanf("%d %d", &N,&prize);
    for(int i=0; i<N; i++){
        scanf("%d",&parti[i]);
    }
    qsort(parti,N,sizeof(int),compare);
    printf("%d", parti[N-prize]);
    return 0;
}