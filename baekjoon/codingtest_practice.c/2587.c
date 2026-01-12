#include <stdio.h>
#include <stdlib.h>
int num[5];
int total;
int compare(const int *a, const int *b){
    return *a - *b;
};
int main(void){
    for(int i=0; i<5; i++){
        int n;
        scanf("%d",&num[i]);
        total += num[i];
    }
    qsort(num,5,sizeof(int),compare);
    printf("%d\n%d",total/5,num[2]);
    return 0;
}