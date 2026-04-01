- 문제 복기
1. 치킨 거리 구하는 방법도 알려줬는데 아무 생각없이 최단거리라는 단어만 보고 BFS로 시도했다.. 가능은 했겠지만 시간 초과 났을듯?
2. 얼마전에 조합 구하는 문제를 풀었어서 조합을 얻어내는 코드를 만드는건 어렵지 않았다.
3. pair 2개를 사용해서 쉽게 구현할 수 있었다.

- 최종 코드
```c++
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int N,M,tot_ch,tot_h,locate;
int min_dist = 0xffffff;

vector<pair<int,int>> chicken; // 치킨집 좌표 모음.
vector<pair<int,int>> home; // 집 좌표 모음
bool idx_ch[13];
// return 받은 값들 다 더해서 min_dist랑 비교해서 update
// 치킨집 고르기 & 거리 구하기 함수 호출
void SELECT(int start, int cnt){
    // 선택된 조합만 호출하여 계산
    if(cnt == M){
        int sum_dist=0;
        for(int h=0; h<tot_h; h++){
            int ch_street = 0xffff;
            int tmp = 0;
            int hy = home[h].first;
            int hx = home[h].second;
            for(int c=0; c<tot_ch; c++){
                if(idx_ch[c]==1){
                    int cy = chicken[c].first;
                    int cx = chicken[c].second;
                    tmp = abs(hy-cy) + abs(hx - cx);
                    if(ch_street > tmp) ch_street = tmp;
                }
            }
            sum_dist += ch_street;
        }
        if(min_dist > sum_dist)  min_dist = sum_dist;
    }
    for(int j=start; j<tot_ch; j++){
        if(idx_ch[j]==0){
            idx_ch[j]=1;
            SELECT(j+1,cnt+1);
            idx_ch[j]=0;
        }
    }
}
int main(void){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> locate;
            if(locate==2){
                chicken.push_back({i,j});
            } else if(locate==1){
                home.push_back({i,j});
            } 
        }
    }
    tot_ch = chicken.size(); // 입력받은 치킨집 총 개수
    tot_h = home.size();
    SELECT(0,0);
    cout << min_dist;
    return 0;
}
```