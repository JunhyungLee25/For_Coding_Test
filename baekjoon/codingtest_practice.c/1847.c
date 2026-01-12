#include <stdio.h>
#include <stdlib.h>
#define MAX 100001
int stack[MAX];
int top = -1;
void push(int n){stack[++top] = n;}
int pop(){return stack[top--];}
char res[MAX*4];
int main(void){
    int n,num,k=1,idx = 0;
    scanf("%d",&n);
    for(int i=1; i<n+1; i++){
        scanf("%d",&num);
        if(top != -1 && num == stack[top]) {
                pop();
                res[idx++]='-';
                res[idx++]='\n';
        }
        else if(stack[top]>num){
            printf("NO");
            return 0;
        }
        else{
            while(k<=num){
            push(k++);
            res[idx++]='+';
            res[idx++]='\n';
            }
            pop();
            res[idx++]='-';
            res[idx++]='\n';
        }
    }
    printf("%s\n", res);
    return 0;
}