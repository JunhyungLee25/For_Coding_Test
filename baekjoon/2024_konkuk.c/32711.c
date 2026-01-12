#include <stdio.h>
int main(void){
    int t,a,o=0,e=0;
    scanf("%d",&t);
    int n[200001]={0,};
    for(int i=0; i<t; i++){
        scanf("%d",&a);
        if(a%2==0){
            n[i]=0;
            e++;
        }
        else {
            n[i]=1;
            o++;
        }
    }
    if(t==1 && o==1){
        printf("1\n");
        return 0;
    }
    if(o%2==1){
        printf("1\n");
    }
    else{
        int k=0,ok=0;
        for(int i=0; i<t-1; i++){
            if(n[i]==1){
                k++;
                if(k%2==0){
                    ok=1;
                    break;
                }
            }
        }
        if(ok==1){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}