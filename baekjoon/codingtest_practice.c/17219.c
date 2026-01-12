#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 100000

typedef struct  PASSWORD{
    char site[21];
    char pwd[21];                   
    struct PASSWORD* next; 
} PSWD;
PSWD* hash[TABLE_SIZE] = {NULL,};

char site[21];
char pwd[21];
unsigned int hash_djb2(const char* str) {
    unsigned long hash_val = 5381; 
    int c;

    while (c = *str++) {
        hash_val = ((hash_val << 5) + hash_val) + c; 
    }

    return hash_val % TABLE_SIZE;
}
int main(void){
    int n,m;
    scanf("%d %d", &n,&m);

    for(int i=0; i<n; i++){
        PSWD* newNode = malloc(sizeof(PSWD));
        scanf("%s %s",site,pwd);
        int idx = hash_djb2(site);
        strcpy(newNode->site,site);
        strcpy(newNode->pwd,pwd);
        newNode->next = hash[idx];
        hash[idx] = newNode;
    }
    for(int i=0; i<m; i++){
        scanf("%s", site);
        int find_idx = hash_djb2(site);
        PSWD* FIND = hash[find_idx];
        while(FIND != NULL){
            if(!strcmp(FIND->site, site)){
                printf("%s\n",FIND->pwd);
                break;
            }
            else {FIND = FIND->next;}
        }
    }
    for(int i=0; i<TABLE_SIZE; i++){
        PSWD* curr = hash[i];
        while(curr != NULL){
            PSWD* temp = curr; 
            curr = curr->next; 
            free(temp);        
        }
    }
    return 0;
}