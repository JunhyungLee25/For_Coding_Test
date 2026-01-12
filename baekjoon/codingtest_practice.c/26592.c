#include <stdio.h>

int main(void){
    int n;
    float a,b,h;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%f %f",&a,&b);
        h=(2*a)/b;
        printf("The height of the triangle is %.2f units\n",h);
    }
    return 0;
}