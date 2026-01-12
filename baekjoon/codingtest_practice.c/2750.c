#include<stdio.h>
int main(void){
    int N;
    scanf("%d",&N);
    int num[1000] = {0};
    for(int i=0; i<N; i++){scanf("%d",&num[i]);}
    for(int i=0; i<N-1; i++){
        for(int j=1; j<N-i; j++){
            if(num[j-1] > num[j]){
                int t = num[j]; num[j] = num[j-1]; num[j-1] = t; 
            }
        }
    }
    for(int i=0; i<N; i++){printf("%d\n",num[i]);}
    return 0;
}