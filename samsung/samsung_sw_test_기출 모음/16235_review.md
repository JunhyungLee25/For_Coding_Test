- 문제 복기
1. vector 3차원 배열을 사용하기 보다 deque을 사용하면 더 효율적이다. 삽입 삭제가 빈번히 발생하고, 앞 뒤 삽입 삭제도 많기 때문이다.
2. 봄과 여름을 합치는 부분에서 `tree[i][j].erase(k)`를 하려고 하니 오류가 발생했다. 삭제 할 때마다 내가  많이 하는 실수인데 for문을 돌리기 때문에 삭제하면서 k 인덱스가 증가하면 정의되지 않은 메모리에 접근해 segment fault가 발생할 수 있다. 주의하자.
3. deque을 사용하는게 낯설어서 그렇지 단순 구현 문제라 체감은 훨씬 쉬웠다.

- 최종 코드
```c++
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
```