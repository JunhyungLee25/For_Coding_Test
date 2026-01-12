#include<stdio.h>
int main(){
    int N,M,num;
    int subject[101]={0};
    int basket1[101]={0};
    int basket2[101]={0};
    scanf("%d %d",&N,&M);
    for(int i=1; i<=M; i++){
        scanf("%d",subject[i]);
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d",num);
            if(num==-1){break;}
            else {basket1[num]++;}
        }
    }

}