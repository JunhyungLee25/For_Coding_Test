#include<stdio.h>
#include<string.h>
int main(void) { // e : 짝수 o : 홀수
    while(1) {
        char p[31];
        int one = 0;
        scanf("%s",p);
        if(p[0] == '#') return 0;

        for(int i=0; p[i] != '\0'; i++){
            if(p[i]=='e'){
                if(one%2!=0){
                    p[i]='1';
                    break;
                }
                else {
                    p[i]='0';
                    break;
                }
            }
            else if(p[i]=='o'){
                if(one%2!=0){
                    p[i]='0';
                    break;
                }
                else {
                    p[i]='1';
                    break;
                }
            }
            else if (p[i]=='1') {one++;}
        }
        printf("%s\n",p);
    }
    return 0;
}