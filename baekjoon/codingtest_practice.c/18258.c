#include<stdio.h>
#include<string.h>
#include<stdlib.h> // malloc, free를 위한 헤더

#define SIZE 2000001

typedef struct{
    int *data; // 동적 할당을 위한 포인터로 변경
    int rear, front;
} Queue;

void initQueue(Queue *Q){
    Q->data = (int*)malloc(sizeof(int) * SIZE); // 동적 메모리 할당
    if(Q->data == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    Q->rear = Q->front = 0;
}

int IsEmpty(Queue *Q){
    return Q->rear == Q->front;
}
int IsFull(Queue *Q){
    return Q->rear == SIZE-1;
}

void pushQ(Queue *Q, int value){
    Q->rear++;
    Q->data[Q->rear] = value;
}

int popQ(Queue *Q){
    if(IsEmpty(Q)){
        return -1;
    }
    else {
        Q->front++;
        return Q->data[Q->front];
    }
}

int sizeQ(Queue *Q){
    return Q->rear - Q->front;
}

int frontQ(Queue *Q){
    if(IsEmpty(Q)){
        return -1;
    }
    else {
        return Q->data[Q->front+1];
    }
}

int backQ(Queue *Q){
    if(IsEmpty(Q)){
        return -1;
    }
    else {
        return Q->data[Q->rear];
    }
}

int main(void){
    Queue Q;
    initQueue(&Q);

    int N;
    scanf("%d", &N);
    char S[10];
    for(int i=0; i<N; i++){
        scanf("%s", S);
        if(!strcmp(S, "push")){
            int num;
            scanf("%d", &num);
            pushQ(&Q, num);
        }
        else if(!strcmp(S, "pop")){
            printf("%d\n", popQ(&Q));
        }
        else if(!strcmp(S, "size")){
            printf("%d\n", sizeQ(&Q));
        }
        else if(!strcmp(S, "empty")){
            printf("%d\n", IsEmpty(&Q));
        }
        else if(!strcmp(S, "front")){
            printf("%d\n", frontQ(&Q));
        }
        else if(!strcmp(S, "back")){
            printf("%d\n", backQ(&Q));
        }
        else {
            free(Q.data); // 프로그램 종료 전 메모리 해제
            return 0;
        }
    }
    
    free(Q.data); // 프로그램 종료 전 메모리 해제
    return 0;
}