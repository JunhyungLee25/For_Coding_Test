#include<stdio.h>
#include<string.h>
int main(){
    char word[100];
    scanf("%s",word);
    int wordlength = strlen(word);
    for(int i=0; i<wordlength/2; i++){
        if(word[i]!=word[wordlength-i-1]){
            printf("0");
            return 0;
        }
    }
    printf("1");
    return 0;
}