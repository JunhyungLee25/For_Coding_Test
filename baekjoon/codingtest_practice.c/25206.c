#include<stdio.h>
int main(){
    double N,num=0,total=0;
    char major[51]={0};
    char grade[2]={0};
    for(int i=0; i<20; i++){
        scanf("%s %lf %s",major,&N,grade);
        if(grade[0]=='A'){
            if(grade[1]=='+'){total += 4.5*N;}
            else{total += 4.0*N;}
            num += N;
        }
        else if(grade[0]=='B'){
            if(grade[1]=='+'){total += 3.5*N;}
            else{total += 3.0*N;}
            num += N;
        }
        else if(grade[0]=='C'){
            if(grade[1]=='+'){total += 2.5*N;}
            else{total += 2.0*N;}
            num += N;
        }
        else if(grade[0]=='D'){
            if(grade[1]=='+'){total += 1.5*N;}
            else{total += 1.0*N;}
            num += N;
        }
        else if(grade[0]=='F'){
            num += N;
        }
        else {continue;}
    }
    printf("%f",total/num);
    return 0;
}
