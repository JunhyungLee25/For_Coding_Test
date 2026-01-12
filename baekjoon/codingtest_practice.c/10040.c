#include <stdio.h>
int game[1001];
int score[1001];
int best[1001];
int main(void){
    int n,m;
    scanf("%d %d", &n,&m);

    for(int i=0; i<n; i++){
        scanf("%d",&game[i]);
    }
    for(int j=0; j<m; j++){
        scanf("%d",&score[j]);
    }
    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            if(game[i]<=score[j]){
                best[i]++;
                break;
            }
        }
    }
    int best_score = best[0];
    int best_game = 1;
    for(int i=1; i<n; i++){
        if(best_score < best[i]){
            best_score = best[i];
            best_game = i+1;
        }
    }
    printf("%d", best_game);
    return 0;
}