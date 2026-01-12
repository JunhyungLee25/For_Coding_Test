/*두개의 스택을 이용하여 푸는것.
cursor를 left스택과 right 스택 사이에 있다고 생각.
"L"이면 left에 있는걸 pop해서 right에 push함 그럼 cursor가 왼쪽으로 가는거랑 같은 효과
삭제는 단순히 left에서 pop. 삽입은 left에 push.
*/

#include <stdio.h>
#include <string.h>

int leftsize=0;
int rightsize=0;


void L(char *left, char *right) {
    if (leftsize==0) return;
    *(right+rightsize)=*(left+leftsize-1);
    *(left+leftsize-1)='\0';
    leftsize--;
    rightsize++;
}
void D(char *left, char *right) {
    if (rightsize==0) return;
    *(left+leftsize)=*(right+rightsize-1);
    *(right+rightsize-1)='\0';
    rightsize--;
    leftsize++;
}
void B(char *left) {
    if (leftsize==0) return;
    *(left+leftsize-1)='\0';
    leftsize--;
}

void P(char *left, char value) {
    *(left+leftsize)=value;
    *(left+leftsize+1)='\0';
    leftsize++;
}

int main(void) {
    int count;
    char instruction[100];
    char left[700000];
    char right[700000]={'\0'};
    printf("%s",right);
    char value;
    scanf("%s", left);
    leftsize=strlen(left);
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        scanf("%s", instruction);
        if (strcmp(instruction, "L") == 0) {
            L(left,right);
        }
        else if (strcmp(instruction, "D") == 0) {
            D(left,right);
        }
        else if (strcmp(instruction, "B") == 0) {
            B(left);
        }
        else if (strcmp(instruction, "P") == 0) {
            scanf(" %c", &value);
            P(left, value);
        }
    }
    printf("%s", left);
    for (int i=rightsize-1;i>=0;i--) {
        printf("%c", right[i]);
     }
    return 0;
}
