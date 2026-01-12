#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct edit{
    char word;
    struct edit* left;
    struct edit* right;
}EDIT;
EDIT *head,*tail,*cursor;
void insert_before_tail(char w, EDIT* cursor){
    EDIT* insert=(EDIT*)malloc(sizeof(EDIT));
    insert->word = w;
    insert->right=tail;
    insert->left=tail->left;
    tail->left->right=insert;
    tail->left=insert;
}
void insert_before_cursor(char w, EDIT* cursor){
    EDIT* insert=(EDIT*)malloc(sizeof(EDIT));
    insert->word = w;
    insert->left = cursor->left;
    insert->right=cursor;
    cursor->left=insert;
    insert->left->right=insert;
}
void print_list(){
    EDIT* p= head->right;
    while(p!=tail){
        printf("%c",p->word);
        p=p->right;
    }
    printf("\n");
}
int main(void){ 
    head = (EDIT*)malloc(sizeof(EDIT));
    tail = (EDIT*)malloc(sizeof(EDIT));
    head->left = NULL;
    head->right = tail;
    tail->left = head;
    tail->right = NULL;
    cursor = tail;

    char n[100001];
    char result;
    int m;
    char order;
    scanf("%s",&n);
    int len = strlen(n);
    for(int i=0; i<len; i++){insert_before_tail(n[i],cursor);}
    scanf("%d",&m);
    while(m--){
        scanf(" %c",&order);
        if(order == 'L'){
            if(cursor->left!=head){cursor = cursor->left;}
        }else if(order == 'D'){
            if(cursor!=tail){cursor = cursor->right;}
            
        }else if(order == 'B'){
            if(cursor->left!=head){
                EDIT* del;
                del = cursor->left;
                cursor->left=del->left;
                del->left->right=cursor;
                free(del);
            }
        }else{
            char w;
            scanf(" %c", &w);
            insert_before_cursor(w,cursor);
        }
    }
    print_list();
    return 0;
}