#include<stdio.h>
#define SIZE 100001

typedef struct {
    int Z[SIZE];
    int top;
} Stack;

int IsEmpty(Stack *s){
    return s->top == -1;
}
int IsFull(Stack *s){
    return s->top == SIZE-1;
}

int push(Stack *s, int data){
    if(IsFull(s)) return 0;
    s->Z[++s->top] = data;
    return 1;
}
int pop(Stack *s){
    if(IsEmpty(s)) return 0;
    s->top--;
    return 1;
}

int main(void){
    Stack s;
    s.top = -1;
    
    int N, sum=0; 
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int num;
        scanf("%d", &num);
        if(num == 0) pop(&s);
        else push(&s, num);
    }
    for(int i=0; i<=s.top; i++){
        sum += s.Z[i];
    }
    printf("%d", sum);
    return 0;
}