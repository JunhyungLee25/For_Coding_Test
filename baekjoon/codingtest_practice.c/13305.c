// 현재 위치 기름값이랑 다음 위치 기름값 비교해서 더 싼곳에서만 계산
#include<stdio.h>
int main(void){
    int N;
    scanf("%d",&N);
    long long distance[100001];
    long long oil_money[100001];
    for(int i=0; i<N-1; i++){scanf("%lld", &distance[i]);}
    for(int i=0; i<N; i++){scanf("%lld", &oil_money[i]);}
    long long total_money = 0;
    for(int i=0; i<N-1; i++){
        if(oil_money[i] < oil_money[i+1]){oil_money[i+1] = oil_money[i];}
        total_money += oil_money[i]*distance[i];
    }
    printf("%lld",total_money);
    return 0;
}