#include<iostream>
using namespace std;

int N,M,R; //N,M 짝수
int map[101][101];
int cpmap[101][101];

void COPY_MAP(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            map[i][j] = cpmap[i][j];
        }
    }
}
void cal_1(){
    for(int i=0; i<N/2; i++){
        for(int j=0; j<M; j++){
            cpmap[i][j] = map[N-1-i][j];
            cpmap[N-1-i][j] = map[i][j];  
        }
    }
    COPY_MAP();
}

void cal_2(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M/2; j++){
            cpmap[i][M-1-j] = map[i][j];
            cpmap[i][j] = map[i][M-1-j];  
        }
    } 
    COPY_MAP();
}

void cal_3(){
    int tp = N;
    N = M;
    M = tp;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cpmap[i][j] = map[tp-1-j][i];
        }
    }
    COPY_MAP();
}

void cal_4(){
    int tp = M;
    M = N;
    N = tp;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cpmap[i][j] = map[j][tp-1-i];
        }
    }
    COPY_MAP();
}

void cal_5(){
    // 1->2
    for(int i=0; i<N/2; i++){
        for(int j=0; j<M/2; j++){
            cpmap[i][j+M/2] = map[i][j];
        }
    }
    // 2->3
    for(int i=0; i<N/2; i++){
        for(int j=M/2; j<M; j++){
            cpmap[i+N/2][j] = map[i][j];
        }
    }
    // 3->4
    for(int i=N/2; i<N; i++){
        for(int j=M/2; j<M; j++){
            cpmap[i][j-M/2] = map[i][j];
        }
    }
    // 4->1
    for(int i=N/2; i<N; i++){
        for(int j=0; j<M/2; j++){
            cpmap[i-N/2][j] = map[i][j];
        }
    }
    COPY_MAP();
}

void cal_6(){
    // 1->4
    for(int i=0; i<N/2; i++){
        for(int j=0; j<M/2; j++){
            cpmap[i+N/2][j] = map[i][j];
        }
    }
    // 4->3
    for(int i=N/2; i<N; i++){
        for(int j=0; j<M/2; j++){
            cpmap[i][j+M/2] = map[i][j];
        }
    }
    // 3->2
    for(int i=N/2; i<N; i++){
        for(int j=M/2; j<M; j++){
            cpmap[i-N/2][j] = map[i][j];
        }
    }
    // 2->1
    for(int i=0; i<N/2; i++){
        for(int j=M/2; j<M; j++){
            cpmap[i][j-M/2] = map[i][j];
        }
    }
    
    COPY_MAP();
}

int main(void){
    cin >> N >> M >> R;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<R; i++){
        int a;
        cin >> a;
        if(a==1) cal_1();
        else if(a==2) cal_2();
        else if(a==3) cal_3();
        else if(a==4) cal_4();
        else if(a==5) cal_5();
        else if(a==6) cal_6();
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}