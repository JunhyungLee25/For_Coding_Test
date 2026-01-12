#include <stdio.h>
#include <stdlib.h>
int set[20]; //0~19

// void add(int k){
//     if(set[k-1]==1){return;}
//     else{set[k-1]=1;}
// }
// void remove_set(int k){
//     if(set[k-1]==0){return;}
//     else{set[k-1]=0;}
// }
// void toggle(int k){
//     if(set[k-1]==0){set[k-1]=1;}
//     else{set[k-1]=0;}
// }
// void all(){
//     for(int i=0; i<20; i++){
//         set[i]=i+1;
//     }
// }
// void empty(int k){
//     for(int i=0; i<20; i++){
//         set[i]=0;
//     }
// }
// int check(int k){
//     if(set[k-1]==0){printf("0\n");}
//     else{printf("1\n");}
//     return 0;
// }

int main(){
    int N,m;
    char *order[10];
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%s",order);
        if(!strcmp(order, "all")){
            for(int i=0; i<20; i++){
                set[i]=i+1;
            } 
        }
        else{
            scanf("%d", &m);
            if(!strcmp(order,"add")){
                if(set[m-1]==1){continue;}
                else{set[m-1]=1;}
            }
            else if(!strcmp(order,"remove")){
                if(set[m-1]==0){continue;}
                else{set[m-1]=0;}
            }
            else if(!strcmp(order,"toggle")){
                if(set[m-1]==0){set[m-1]=1;}
                else{set[m-1]=0;}
            }
            else if(!strcmp(order,"empty")){
                for(int i=0; i<20; i++){
                    set[i]=0;
                }
            }
            else if(!strcmp(order,"check")){
                if(set[m-1]==0){printf("0\n");}
                else{printf("1\n");}            
            }
            else {continue;}
        }
    }
    return 0;
}