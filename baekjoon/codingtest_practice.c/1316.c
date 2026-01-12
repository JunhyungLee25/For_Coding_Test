#include<stdio.h>
#include<string.h>
int main(){
    int N;
    scanf("%d",&N);
    char word[101];

    int count = 0;
    for(int i=0; i<N; i++){
        int flag = 0;
        scanf("%s",word);
        
        for(int j=0; j<strlen(word); j++){
            for(int k=j+2; k<strlen(word); k++){
                if(word[j] != word[j+1] && word[j]==word[k]){
                    flag = 1;
                }
            }
        }
        if(!flag){
            count ++;
        }
    }
    printf("%d", count);
    return 0;
}