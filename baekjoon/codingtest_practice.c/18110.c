// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// int weight[300001];
// int compare(const void *a, const void *b){return *(int*)a - *(int*)b;}
// int main(void){
//     int n,w;
//     scanf("%d",&n);
//     if(n==0){
//         printf("0");
//         return 0;
//     }
//     for(int i=0; i<n; i++){scanf("%d",&weight[i]);}    
//     qsort(weight,n,sizeof(int),compare);
//     int del = round(n*0.15);
//     double mean=0;
//     for(int i=del; i<n-del; i++){mean += weight[i];}
//     if((n-2*del)==0){printf("0");}
//     else{
//         printf("%d",(int)round(mean/(n-2*del)));
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
int w[30];
int main(void){
    int n,a,t;
    scanf("%d",&n);
    if(n==0){
        printf("0");
        return 0;
    }
    for(int i=0; i<n; i++){
        scanf("%d",a);
        w[a-1]++;
        t += a;
    }
    int del = (int)((double)n*0.15+0.5);
    double mean = 0;
    for(int i=0,j=0; i<30; i++){
        
    }
    return 0;
}