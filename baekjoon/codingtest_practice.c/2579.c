#include <stdio.h>
int stair[300];
int score[300];
int max(int a, int b){
    return (a>b) ? a : b;
}
int main(void){
    int n=0,score1,score2;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d", &stair[i]);
    }
    score[0] = stair[0];
    if(n==1){
        printf("%d\n",score[0]);
        return 0;
    }
    score[1] = score[0] + stair[1];
    if(n==2){
        printf("%d\n",score[1]);
        return 0;
    }
    score[2] = max(score[0]+stair[2], stair[1]+stair[2]);
    if(n==3){
        printf("%d\n",score[2]);
        return 0;
    }

    for(int i=3; i<n; i++){
        score[i] = max(score[i-3]+stair[i-1]+stair[i], score[i-2]+stair[i]);
    }
    printf("%d\n",score[n-1]);
    return 0;
}