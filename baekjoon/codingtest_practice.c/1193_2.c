#include <stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    int line,p=n;
    for(int i=1; ; i++){
        p-=i;
        if(p<=0){
            line = i;
            p += i;
            break;
        }
    }
    if(line%2==0){
        printf("%d/%d\n",p,line+1-p);
    }
    else{
        printf("%d/%d\n",line+1-p,p);
    }
    return 0;
}