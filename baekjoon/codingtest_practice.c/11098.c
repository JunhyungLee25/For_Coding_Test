#include <stdio.h>
#include <string.h>
char name[21];
char buy[21];
int main(void){
    int n,p,price;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int m=0;
        scanf("%d",&p);
        for(int j=0; j<p; j++){
            scanf("%d %s",&price,name);
            if(m<price){
                m=price;
                strcpy(buy,name);
            }
        }
        printf("%s\n",buy);
    }
    return 0;
}