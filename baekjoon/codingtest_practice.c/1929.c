#include <stdbool.h> // 0이면 소수, 1이면 아님
int main(void){
    int n1,n2;
    scanf("%d %d", &n1,&n2);
    bool num[1000001]={false};
    num[0]=num[1]=true;
    for(int i=2; i*i<n2+1; i++){
        for(int j=i*i; j<n2+1; j+=i){
            if(j%i == 0){num[j] = true;}
        }
    }
    for(int i=n1; i<n2+1; i++){
        if(!num[i]){printf("%d\n",i);}
    }
    return 0;
}