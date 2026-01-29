## 1. 문제 분석

이 문제는 벽을 세우는 모든 경우의 수를 따져봐야 하므로 구현의 정확성이 핵심이다.

- **격자의 특징**: $N \times M$ 크기이며, 최대 크기가 $8 \times 8$로 매우 작다. 이는 모든 조합을 탐색해도 시간 초과가 나지 않는다는 뜻이다.
    
- **핵심 로직 (3단계)**:
    
    1. **벽 세우기 (Backtracking)**: 빈칸(0) 중 3개를 골라 벽(1)을 세운다. 1차원 인덱스를 활용하여 중복 없는 조합을 구성하였다.
        
    2. **바이러스 유출 (BFS)**: 벽이 없는 부분으로 모든 바이러스(2)가 상하좌우 빈칸으로 퍼져나간다. 원본 지도를 지키기 위해 `tmp_map`을 사용한다.
        
    3. **안전 영역 계산**: 바이러스가 다 퍼진 후, `tmp_map`에서 빈칸(0)의 개수를 세어 최댓값을 갱신한다.
        

---

## 2. 배운 점

- **상태 복구의 중요성 (Backtracking)**: 재귀 함수 호출 후 `map[r][c] = 0;`을 통해 세웠던 벽을 다시 허무는 과정이 반드시 포함되어야 한다.
    
- **데이터 독립성**: 전역 변수인 `map`을 직접 수정하면 다음 시뮬레이션에 영향을 주므로, 매 시뮬레이션마다 `tmp_map`을 생성하여 독립적인 환경을 구축해야 한다.
    
- **BFS의 효율적 구현**: 큐(`queue`)를 사용하여 바이러스가 전파되는 과정을 구현했습니다. 특히 `visited` 배열을 활용하거나, `tmp_map`의 값을 직접 변경하여 중복 방문을 막는 최적화 방법을 고민해 보았습니다.
    
- **조합(Combination) 구현**: 2차원 배열을 1차원으로 간주하여 `i / m`, `i % m`으로 변환해 루프 하나로 조합을 뽑아내는 깔끔한 방식을 배웠다.
    

---

## 3. 최종 코드 및 동작 방식 정리

 빈칸에 최대 3개의 벽을 세우는 모든 조합을 중복없이 찾기 위해 백트래킹을 사용하였고, 바이러스는 연쇄적으로 퍼진다는 특성을 이용하여 BFS를 사용하였다. 특히 큐에서 좌표를 꺼내 상하좌우만 검사하는 구조로 변경하면서 성능을 높였다.

****
### WALL 함수 (조합 & 백트래킹)

이 함수는 연구소 내 빈칸 중 **벽을 세울 수 있는 모든 경우의 수($({N \times M})_C3$)** 를 탐색하는 역할을 한다.

- **작동 방식**:
    1. `start` 인덱스를 활용해 중복 없이 칸을 선택할 수 있다.
        
    2. `i / m`과 `i % m` 연산으로 1차원 인덱스를 2차원 좌표로 변환하여 격자를 순회한다.
        
    3. 빈칸(`0`)을 찾으면 벽(`1`)으로 바꾼다.
        
    4. 다음 벽을 세우기 위해 `WALL(cnt + 1, i + 1)`을 호출한다.
        
    5. 재귀 호출이 끝나고 돌아오면 다음 경우의 수를 위해 다시 빈칸(`0`)으로 되돌린다.
        
- **종료 조건**: 벽이 3개 세워지면(`cnt == 3`) `VIRUS()` 함수를 호출한다.

### VIRUS 함수 (BFS)

세워진 3개의 벽을 바탕으로 **바이러스가 얼마나 퍼지는지** 확인하고 최대 안전 공간을 얻는다.

- **작동 방식**:
    1. 원본 `map`을 `tmp_map`으로 복사한다. 이는 다음 벽 조합을 테스트할 때 원본을 깨끗하게 유지하기 위함이다.
        
    2. **초기화**: `queue`에 원래 바이러스(`2`)가 있던 좌표들을 모두 집어넣는다.
        
    3. BFS: **큐가 빌 때까지 다음 과정을 반복한다.
        
        - 큐에서 바이러스 좌표를 하나 꺼낸다.
            
        - 상하좌우 4방향을 검사하여 **범위 내에 있고, 빈칸(`0`)이며, 방문하지 않은 곳**을 찾는다.
            
        - 해당 칸을 감염시키고(`1` 또는 `2`로 변경), 다시 큐에 넣어 그 칸에서도 바이러스가 퍼지게 한다.
            
    4. **결과 도출**: 확산이 끝난 후 `tmp_map` 전체를 순회하며 바이러스가 닿지 않은 안전 영역(`0`)의 개수를 카운트한다.
``
```c++
#include<iostream>
#include<queue>
using namespace std;
int max_safe=0;
int map[8][8];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int n,m;
void VIRUS(){
    int safe_zone=0;
    int tmp_map[8][8];
    int visited[8][8]={0};
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            tmp_map[i][j] = map[i][j];
            if(map[i][j]==2) q.push(make_pair(i,j)); 
        }
    }
    while(!q.empty()){
        int tp1 = q.front().first;
        int tp2 = q.front().second;
        visited[tp1][tp2]=1;
        q.pop();
        for(int k=0; k<4; k++){
            if((0<=tp1+dy[k] && tp1+dy[k]<n) && (0<=tp2+dx[k] && tp2+dx[k]<m) && !tmp_map[tp1+dy[k]][tp2+dx[k]] && !visited[tp1+dy[k]][tp2+dx[k]]){
                tmp_map[tp1+dy[k]][tp2+dx[k]]=1;
                q.push(make_pair(tp1+dy[k],tp2+dx[k]));
                visited[tp1+dy[k]][tp2+dx[k]]=1;
            }
        }
    }    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tmp_map[i][j]==0) safe_zone++;
        }
    }
    if(max_safe<safe_zone) max_safe=safe_zone;
}
void WALL(int cnt,int start){
    if(cnt==3){
        VIRUS();
        return;
    } 
    for (int i = start; i < n * m; i++) {
        int r = i / m;
        int c = i % m; 
        if (map[r][c] == 0) {
            map[r][c] = 1;
            WALL(cnt + 1, i + 1);
            map[r][c] = 0;
        }
    }
}
int main(void){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    WALL(0,0);
    cout << max_safe;
    return 0;
}
```