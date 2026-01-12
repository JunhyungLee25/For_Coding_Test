#include<stdio.h>
#include<string.h>
int main(){
    char CA[101]={0};
    scanf("%s",CA);
    int len = strlen(CA);
    int total = 0;
    for(int i=0; i<len; i++){
        if(CA[i]=='c'){
            if(CA[i+1]=='='||CA[i+1]=='-'){
                total++;
                i++; 
            } else{total++;}
        }
        else if(CA[i]=='d'){
            if(CA[i+1]=='z'){
                if(CA[i+2]=='='){
                    total++;
                    i=i+2;
                } else{total++;}
            }
            else if(CA[i+1]=='-'){
                total++;
                i++;
            } else{total++;}
        }
        else if(CA[i]=='l'){
            if(CA[i+1]=='j'){
                total++;
                i++;
            } else{total++;}
        }
        else if(CA[i]=='n'){
            if(CA[i+1]=='j'){
                total++;
                i++;
            } else{total++;}
        }
        else if(CA[i]=='s'){
            if(CA[i+1]=='='){
                total++;
                i++;
            } else{total++;}
        }
        else if(CA[i]=='z'){
            if(CA[i+1]=='='){
                total++;
                i++;
            } else{total++;}
        }
        else{total++;}
    }
    printf("%d",total);
    return 0;
}