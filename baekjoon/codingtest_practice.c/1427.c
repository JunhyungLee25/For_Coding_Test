// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// char str_num[11];
// int int_num[10];
// int compare(const int  *a, const int *b){return *a-*b;}
// int main(void){
//     scanf("%s",str_num);
//     int size = strlen(str_num);
//     for(int i=0; i<size; i++){
//         int_num[i] = str_num[i] - '0';
//     }
//     qsort(int_num, size, sizeof(int), compare);
//     for(int i=size-1; i>=0; i--){
//         printf("%d",int_num[i]);
//     }
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str_num[11];
int compare(const void  *a, const void *b){return (int)(*(char*)b)-(int)(*(char*)a);}
int main(void){
    scanf("%s",str_num);
    int size = strlen(str_num);
    qsort(str_num, size, sizeof(str_num[0]), compare);
    printf("%s",str_num);
    return 0;
}