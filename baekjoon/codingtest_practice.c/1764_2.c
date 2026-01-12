#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int compare(const void*a, const void*b){return strcmp((char*)a, (char*)b);}

char (*name_n)[21];
char (*name_m)[21];
char same[500001][21];
int count;
int main(void){
    int n,m;
    scanf("%d %d", &n,&m);

    name_n = malloc(sizeof(char[21])*n);
    name_m = malloc(sizeof(char[21])*m);
    for(int i=0; i<n; i++){
        scanf("%s", name_n[i]);
    }

    for(int i=0; i<m; i++){
    scanf("%s", name_m[i]);
    }
    qsort(name_n, n, sizeof(name_n[0]), compare);
    qsort(name_m, m, sizeof(name_m[0]), compare);

    for(int i=0,j=0; i<n&&j<m;){
        int cmp = strcmp(name_n[i],name_m[j]);

        if(cmp == 0){
            strcpy(same[count],name_n[i]);
            count++;
            i++;
            j++;
        }
        else if(cmp < 0){
            i++;
        }
        else if(cmp >0){
            j++;
        }
        else{continue;}
    }
    printf("%d\n",count);
    for(int i=0; i<count; i++){
        printf("%s\n",same[i]);
    }
    free(name_n);
    free(name_m);
    
    return 0;
}