// #include<stdio.h>
// char ISBN[14];
// int total;
// int num;
// int main(void){
//     scanf("%s",ISBN);
//     // for(int i=0; i<13; i++){
//     //     if(i % 2 == 0 && ISBN[i] != '*'){
//     //         total += ISBN[i]-'0';    
//     //     }else if(i % 2 == 1 && ISBN[i] != '*'){
//     //         total += 3*(ISBN[i]-'0');
//     //     }
//     //     else{num = i;}
//     // }
//     for(int i=0; i<13; i++){
//         if(ISBN[i] == '*'){
//             num = i;
//         }
//         else{
//             if(i % 2 == 0){total += ISBN[i]-'0';}
//             else { total += 3*(ISBN[i]-'0');}
//         }
//     }
//     int res;
//     if(num % 2 ==0){
//         for(int i=0; i<10; i++){
//             if((total + i)%10 == 0){
//                 res = i;
//                 break;
//             }
//         }
//     }
//     else {
//         for(int i=0; i<10; i++){
//             if((total + 3*i)%10 == 0){
//                 res = i;
//                 break;
//             }
//         }
//     }
//     printf("%d",res);
//     return 0;
// }

#include <stdio.h>
int main(void){
    char ISBN[14];
    scanf("%s",ISBN);
    int idx;
    for(int i=0; i<13; i++){
        if(ISBN[i] == '*'){
            idx = i;
            break;
        }
    }
    for(int i=0; i<10; i++){
        int res = 0;
        ISBN[idx] = i + '0';
        for(int j=0; j<13; j++){
            if(j % 2 == 0){res += ISBN[j]-'0';}
            else{res += 3*(ISBN[j]-'0');}
        }
        if(res % 10 == 0){
            printf("%d",i); 
            break;
        }
    }
    return 0;
}