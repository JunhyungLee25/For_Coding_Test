#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void){
    char N[1000];
    int B;
    scanf("%s %d", &N, &B);
    int len = strlen(N);
    int output = 0;
    for(int i=0; i<len; i++){
        int num;
        if(N[i]>='0' && N[i]<= '9'){
            num = N[i]-'0';}
        else{num = N[i] -'A' +10;}
        output += num*pow(B,len-i-1);
    }
    printf("%d",output);
    return 0;
}