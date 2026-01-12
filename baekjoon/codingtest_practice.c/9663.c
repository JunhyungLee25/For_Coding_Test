#include<stdio.h>
#include<math.h>
int N;
int board[15];
int total;
int check(int k){ // 행
    for(int i=0; i<k; i++){
        if(board[k]==board[i] || abs(board[k]-board[i]) == (k-i)){return 0;}
    }
    return 1;
}
void place_queen(int x){
    if(x == N){
        total++;
        return;
    }
    for(int y=0; y<N; y++){
        board[x]=y;
        if(check(x)){place_queen(x+1);}
    }
}
int main(void){
    scanf("%d",&N);
    place_queen(0);
    printf("%d",total);
    return 0;
}