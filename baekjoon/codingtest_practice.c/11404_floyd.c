#include<stdio.h>
#define MAX 101
#define MAX_LENGTH 100001
#define INF 987654321
int all_line[MAX][MAX];
int start[MAX_LENGTH],end[MAX_LENGTH],money[MAX_LENGTH];

void compute_money(int c, int b, int al[][MAX], int s[MAX], int e[MAX], int m[MAX]){
    int i,j,k;
    for(i=1; i<=c; i++){
        for(j=1; j<=c; j++){
            if(i==j){al[i][j]=0;}
            else{al[i][j] = INF;}
        }
    }
    for(i=1; i<=b; i++){
        if(al[s[i]][e[i]] > m[i]){
            al[s[i]][e[i]] = m[i];
        }
    }
    for(k=1; k<=c; k++){
        for(i=1; i<=c; i++){
            for(j=1; j<=c; j++){    
                if(al[i][k] != INF && al[k][j] != INF){
                    if(al[i][j] > al[i][k] + al[k][j]){
                        al[i][j] = al[i][k] + al[k][j];
                    }
                }               
            }
        }
    }
}
int main(void){
    int city_n,bus_n;
    scanf("%d", &city_n);
    scanf("%d", &bus_n);

    for(int i=1; i<=bus_n; i++){
        scanf("%d %d %d", &start[i],&end[i],&money[i]);
    }
    compute_money(city_n,bus_n, all_line, start, end, money);
    for(int i=1; i<=city_n; i++){
        for(int j=1; j<=city_n; j++){
            if(all_line[i][j] == INF){printf("0 ");}
            else {printf("%d ",all_line[i][j]);}
        }
        printf("\n");
    }
    return 0;
}