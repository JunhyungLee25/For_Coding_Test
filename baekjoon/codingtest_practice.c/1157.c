#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    char word[1000001];
    scanf("%s",word);
    int count[26] = {0};
    int max = 0,alphabet = 0;
    int length = strlen(word);
    for(int i=0; i<length; i++){
        char Word = toupper(word[i]);
        count[Word-'A']++;
    }
    for(int i=0; i<26; i++){
        if(max < count[i]){
            max = count[i];
            alphabet = i;
        }
    }
    int check = 0;
    for(int i=0; i<26; i++){
        if(max == count[i]){
            check++;
        }
    }
    if(check>1){
        printf("?");
    }
    else{
        printf("%c",alphabet+'A');
    }
    return 0;
}