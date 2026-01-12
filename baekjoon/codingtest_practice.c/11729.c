// 1. n-1개를 A->B!
// 2. n을 A->C!
// 3. n-1을 B->C!

#include<stdio.h>
#include<math.h>
void moveto(int from, int to){
    printf("%d %d\n",from, to);
}

void hanoi(int n, int from, int via, int to){
    if(n==1){
        moveto(from,to);
    }
    else{
        hanoi(n-1, from,to,via);
        moveto(from,to);
        hanoi(n-1,via,from,to);
    }
}

int main(void){
    int N,K;
    scanf("%d",&N);
    K = pow(2,N)-1;
    printf("%d\n",K);
    hanoi(N,1,2,3);
    return 0;
}