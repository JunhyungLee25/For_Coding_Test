// #include<stdio.h>
// int main(){
//     int N;
//     scanf("%d",&N);
//     for(int i=0; i<N/4; i++){
//         printf("long ");
//     }
//     printf("int");
//     return 0;
// }

#include <stdio.h>

int main() {
    int num;
    char ch;
    
    printf("정수를 입력하세요: ");
    scanf("%d", &num);
    while (getchar() != '\n');  // 개행 문자 제거
    printf("문자를 입력하세요: ");
    scanf("%c", &ch); // 문제 발생: 이전 입력의 개행이 남아 있음
    
    printf("입력된 값: %d, %c\n", num, ch);
    return 0;
}

