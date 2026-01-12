#include<stdio.h>
int weight[51];
int height[51];
int result[51];
int main(void){
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d %d",&weight[i],&height[i]);
    }
    for(int i=0; i<n; i++){
        int rank=1;
        for(int j=0; j<n; j++){
            if(weight[i]<weight[j] && height[i]<height[j]){rank++;}
        }
        result[i]=rank;
    }
    for(int i=0; i<n; i++){
        printf("%d ",result[i]);
    }
    return 0;
}