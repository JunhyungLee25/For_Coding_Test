#include <stdio.h>
#include<stdlib.h>
#define SIZE 1000
int order=1;
typedef struct node{
    int key;
    struct node* next;
}node;
node *DL[SIZE];
int visited[SIZE];

int stack[SIZE];
int top;
void init_stack(void){ top = -1; }
int push(int t){
    if(top >= SIZE - 1){ printf("Stack overflow\n"); return -1; }
    return stack[++top] = t;
}
int pop(){
    if(top < 0){ printf("Stack underflow\n"); return -1; }
    return stack[top--];
}
int stack_empty(){
    return (top < 0);
}

void input_DL(node *DL[], int V, int E)
{
    int i, j;
    int v1,v2;
    node *t;    
    for(i=0; i<V; i++){
        DL[i]=NULL;
    }
    for(i=0; i<E; i++){
        scanf("%d %d",&v1,&v2);
        t=(node *)malloc(sizeof(node));
        t->key = v2;
        t->next=DL[v1];
        DL[v1]=t;
        t=(node *)malloc(sizeof(node));
        t->key=v1;
        t->next=DL[v2];
        DL[v2]=t;
    }
}

void DFS(int V, int E, int R)
{

    if(visited[R]){
        return;
    }        
    visited[R]=order++;
    node *t = DL[R];
    while(t!=NULL){
        if(visited[t->key]==0){
            DFS(V,E,t->key);
        }
        t=t->next;
    }
}
int main(void)
{
    int N, M, R; // N : 정점 개수, M : 간선 개수, R : 시작 노드.
    scanf("%d %d %d", &N, &M, &R);
    input_DL(DL, N,M);
    DFS(N, M, R);
    for(int i=1; i<=N; i++){
        printf("%d\n",visited[i]);
    }
    return 0;
}