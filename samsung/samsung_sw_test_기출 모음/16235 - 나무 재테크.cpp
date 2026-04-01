#include<iostream>
#include<deque>
using namespace std;

int N,M,K,result;
int dr[8] = {-1,-1,0,1,1,1,0,-1};
int dc[8] = {0,1,1,1,0,-1,-1,-1};

int ground[11][11];
deque<int> tree[11][11];
int nutrient[11][11];

void fourWeather(){
    // spring & summer
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int death_tree_nt=0;
            for(int k=0; k<tree[i][j].size(); k++){
                if(ground[i][j] >= tree[i][j][k]){
                    ground[i][j] -= tree[i][j][k]; // 1. 양분 먹기
                    tree[i][j][k]++; // 2. 나이 증가 후 저장
                } else{
                    while(k<tree[i][j].size()){
                        death_tree_nt += tree[i][j].back()/2;
                        tree[i][j].pop_back();
                    }
                    break;
                }
            }
            ground[i][j] += death_tree_nt;
        }
    }
    // fall
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<tree[i][j].size(); k++){
                if(tree[i][j][k]%5==0){
                    for(int dir=0; dir<8; dir++){
                        int nr = i + dr[dir];
                        int nc = j + dc[dir];
                        if(nr<0||nc<0||nr>=N||nc>=N) continue;
                        tree[nr][nc].push_front(1);
                    }
                } 
            }
        }
    }
    // winter
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            ground[i][j] += nutrient[i][j];
        }
    }
}
int main(void){
    cin >> N >> M >> K;
    // init 
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            ground[i][j]=5;
        }
    }
    // input
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> nutrient[i][j];
        }
    }
    for(int i=0; i<M; i++){
        int ty,tx,year;
        cin >> ty >> tx >> year;
        tree[ty-1][tx-1].push_back(year);
    }
    for(int i=0; i<K; i++){
        fourWeather();
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            result += tree[i][j].size();
        }
    }
    cout << result;
    return 0;
}