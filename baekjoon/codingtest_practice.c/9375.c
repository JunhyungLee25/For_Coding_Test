#include <stdio.h>
#include <string.h>
typedef struct FASHION{
    char type[21];
    int count;
}FASION;
char name[21];
char type[21];
int main(void){
    int t,n;
    scanf("%d",&t);
    for(int i=0; i<t; i++){
        scanf("%d",&n);
        FASION F[30];
        int t_count=0;
        for(int j=0; j<n; j++){
            scanf("%s %s",name,type);
            int found=0;
            for(int h=0; h<t_count; h++){
                if(!strcmp(F[h].type,type)){
                    F[h].count++;
                    found = 1;
                    break;
                }
            }
            if(found == 0){
                strcpy(F[t_count].type,type);
                F[t_count].count=1;
                t_count++;
            }
        }
        int result = 1;
        for(int i=0; i<t_count; i++){
            result *= (F[i].count+1);
        }
        printf("%d\n",result-1);
    }
    return 0;
}