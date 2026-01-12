#include<stdio.h>
#include<string.h>
#define SIZE 102

typedef struct {
    char data[SIZE];
    int top;
} Stack;

void init(Stack *s)
{ s->top = -1; }

int IsEmpty(Stack *s){
    return s->top == -1;
}
int IsFull(Stack *s){
    return s->top == SIZE - 1;
}
void push(Stack *s, char wd){
    if(IsFull(s)){
        return;
    }
    else {
        s->data[++s->top] = wd;
    }
}
char pop(Stack *s){
    if(IsEmpty(s)){
        return '\0';  // 빈 경우에는 널 문자 반환
    }
    else {
        return s->data[s->top--];
    }
}
int main(void){
    char W[SIZE], result;

    while (1){
        int flag = 0;
        Stack s;
        init(&s);

        fgets(W, sizeof(W), stdin);
        if (strcmp(W, ".\n") == 0) break;  // 종료 조건

        for(int i=0; i<strlen(W); i++){
            if(W[i] == '(' || W[i] == '['){
                push(&s, W[i]);
            }
            else if(W[i] == ')'){
                result = pop(&s);
                if(result != '('){
                    flag = 1;
                    break;
                }
            }
            else if(W[i] == ']'){
                result = pop(&s);
                if(result != '['){
                    flag = 1;
                    break;
                }
            }
        }
        if(!IsEmpty(&s) || flag == 1){ //if(!IsEmpty || flag == 1){ ... }에서 IsEmpty는 함수 포인터로 취급되어 항상 참(true)처럼 평가됩니다.
            printf("no\n");
        }
        else if(flag == 0){ 
            printf("yes\n");
        }
    }
    return 0;
}