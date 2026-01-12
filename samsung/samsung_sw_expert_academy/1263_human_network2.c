#include<stdio.h>

#define MAX 1001
#define MAX_WEIGHT 50000
int human_network[MAX][MAX];
int dummy_matrix[MAX*MAX];

int compute_CC(int N, int hn[][MAX], int dm[MAX*MAX]){
    int i,j,k;
    int cnt = 0;
    
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(dm[cnt] == 1){
                hn[i][j] = 1;}
            else if(i==j){hn[i][j] = 0;}
            else {hn[i][j] = MAX_WEIGHT;}
            cnt++;
        }
    }
    // 모든 노드의 거리 갱신
    for(k=0; k<N; k++){
        for(i=0; i<N; i++){
            for (j=0; j<N; j++){
                if (hn[i][k] < MAX_WEIGHT && hn[k][j] < MAX_WEIGHT){
                    if(hn[i][j] > hn[i][k] + hn[k][j]){
                        hn[i][j] = hn[i][k] + hn[k][j];
                    }
                }
            }
        }
    }
    // 최솟값 return
    int min = MAX_WEIGHT*N;
    for(i=0; i<N; i++){
        int sum = 0;
        for(j=0; j<N; j++){
            if(i!=j){
                sum += hn[i][j];
            }
        }
        if(sum < min){min = sum;}
    }
    return min;
}

int main(void){
    int T,N;

    scanf("%d",&T);
    for(int i=0; i<T; i++){
        scanf("%d",&N);
        for(int j=0; j<N*N; j++){
            scanf("%d",&dummy_matrix[j]);
        }
        printf("#%d %d\n",i+1,compute_CC(N,human_network,dummy_matrix));
    }
    return 0;
}