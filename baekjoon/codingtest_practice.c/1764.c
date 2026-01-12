#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int compare(const void*a, const void*b){return strcmp((char*)a, (char*)b);}
typedef struct NOSEEHEAR{
    char name[21];
    struct NOSEEHEAR* next; 
} DBJ;
DBJ* dbj_n[26];
DBJ* dbj_m[26];
char who[21];
char same[500001][21];
int count;
int main(void){
    int n,m;
    scanf("%d %d", &n,&m);

    for(int i=0; i<n; i++){
        int idx=0;
        scanf("%s",who);
        DBJ* newNode = (DBJ*)malloc(sizeof(DBJ));
        strcpy(newNode->name, who);
        idx = who[0]-'a';
        newNode->next = dbj_n[idx];
        dbj_n[idx] = newNode;
    }
    for(int i=0; i<m; i++){
        int idx=0;
        scanf("%s",who);
        DBJ* newNode = (DBJ*)malloc(sizeof(DBJ));
        strcpy(newNode->name, who);
        idx = who[0]-'a';
        newNode->next = dbj_m[idx];
        dbj_m[idx] = newNode;
    }
    for(int i=0; i<26; i++){
        DBJ* find_n = dbj_n[i];
        
        while(find_n != NULL){
            DBJ* find_m = dbj_m[i];
            while(find_m != NULL){
                if(!strcmp(find_n->name, find_m->name)){
                    strcpy(same[count],find_n->name);
                    count++;
                    break;
                }
                find_m=find_m->next;
            }
            find_n=find_n->next;
        }
    }
    qsort(same, count, sizeof(same[0]), compare);

    printf("%d\n",count);
    for(int i=0; i<count; i++){
        printf("%s\n",same[i]);
    }
    
    
    for(int i=0; i<26; i++){
        DBJ* fr = dbj_n[i];
        while (fr != NULL) {
            DBJ* temp = fr;
            fr = fr->next;
            free(temp);
        }
    }
    for(int i=0; i<26; i++){
        DBJ* fr = dbj_m[i];
        while (fr != NULL) {
            DBJ* temp = fr;
            fr = fr->next;
            free(temp);
        }
    }

    return 0;
}