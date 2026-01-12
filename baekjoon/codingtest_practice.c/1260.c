#include<stdio.h>
#define SIZE 1001

int queue[SIZE];
int Matrix[SIZE][SIZE];
int check[SIZE];
int rear,front;

void init_queue(){
    front = rear = 0;
}
void put(int k){
    queue[rear++] = k;
}
int get(){
    return queue[front++];
}

void input_matrix(int V,int E,int S){
    int i,j,k;
    for(i=0; i<V; i++){
        for(j=1; j<=V; j++){
            Matrix[i][j]=0;
        }
    }
    for(i=0; i<E; i++){
        scanf("%d %d",&j,&k);
        Matrix[j][k]=1;
        Matrix[k][j]=1;
    }
}
void DFS(int V,int S){
    int i;
    printf("%d ",S);
    check[S]=1;
    for(i=1; i<=V; i++){
        if(check[i] == 0 && Matrix[S][i] == 1){
            DFS(V,i);
        }
    }
    return ;
}
void BFS(int V, int S){
    int i,j;
    init_queue();
    printf("%d ",S);
    for(i=1; i<=V; i++){
        check[i]=0;
    }
    put(S);
    check[S]=1;
    while(front < rear){
        j = get();
        for(i=1; i<=V; i++){
            if(check[i] == 0 && Matrix[j][i] == 1){
                printf("%d ",i);
                put(i);
                check[i] = 1;
        }
    }
    }
    return ;
}

int main(void){
    int i,V,E,Start;
    scanf("%d %d %d",&V,&E,&Start);
    input_matrix(V,E,Start);
    for(i=1; i<=V; i++){
        check[i]=0;
    }
    DFS(V,Start);
    printf("\n");
    BFS(V,Start);
    return 0;
}