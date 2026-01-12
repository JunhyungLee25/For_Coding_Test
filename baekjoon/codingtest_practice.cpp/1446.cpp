#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct ShortCut{
    int start;
    int end;
    int sc;
};
vector<ShortCut> dist;
vector<ShortCut> min_dist;
bool compareShortCut(const ShortCut &a, const ShortCut &b) {
    if (a.start != b.start) return a.start < b.start;
    if (a.end != b.end) return a.end < b.end;
    return a.sc < b.sc;
}
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,d;
    cin >> n >> d;
    int min_distance=0;
    for(int i=0; i<n; i++){
        int s,e,sc;
        cin >> s >> e >> sc;
        int real_dist = e-s;
        if(real_dist < sc || d < e){continue;}
        else{dist.push_back({s,e,sc});} 
    }
    sort(dist.begin(), dist.end(), compareShortCut);
    for(int i=0; i<dist.size(); i++){
        if(i==0 || dist[i].start!=dist[i-1].start || dist[i].end!=dist[i-1].end){min_dist.push_back(dist[i]);}
    }
    int dp[10001]; // idx까지의 최단거리
    int idx = 0;
    for(int i=0; i<=d; i++){dp[i]=i;}
    for(int i=0; i<=d; i++){
        if(i>0)dp[i]= min(dp[i-1]+1,dp[i]);
        while(idx<min_dist.size() && i == min_dist[idx].start){
            dp[min_dist[idx].end] = min(dp[min_dist[idx].end] , dp[i]+min_dist[idx].sc);
            idx++;
        }
    }
    cout << dp[d];
    return 0;
} 

/* 동작방식

1. 지름길의 시작지점, 도착지점, 거리 멤버를 가지고 있는 구조체를 선언한다.
2. 구조체 벡터를 선언한다.
3. n,d를 입력받는다.
4. 구조체 멤버 값을 변수에 미리 입력받고 절대 가지 않는 지름길을 제거한다.
	4-1. 지름길로 가면 더 먼경우
	4-2. 지름길의 도착지점이 목적지보다 먼 경우
5. 지름길의 시작 지점 > 도착 지점 > 거리의 가중치로 정렬
6. 지름길의 시작과 끝이 같은데 거리가 더 긴 경우를 제외하여 다시 구성한다.
7. 최소값을 얻기 위한 index가 위치이고 `dp[index]`=최소거리인 dp 배열을 선언한다.
8. `dp[i]=i`로 초기화한다.
9. 위치0부터 목적지까지 루프를 돈다
	1. `min(dp[i-1]+1, dp[i])` 현재 위치의 최소값을 구한다(i>0 예외처리)
		그냥 걷는 것과 현재 dp 최솟값을 비교하는 목적이다.
	2. 이때 dp의 위치가 지름길의 시작 지점과 같으면 도착 지점의 최솟값을 찾기 위해 while문을 돌린다
		2-1. 현재 위치에서 가능한 지름길의 도착 지점의 현재 최소값과 현재 위치에서 지름길의 도착 지점으로 가는 최소거리를 비교하여 더 작은 값으로 업데이트한다.
		2-2. 시작지점이 동일한 지름길이 여러개 있을 수 있으므로 다음 vector 요소로 넘어가서 비교한다(현재 정렬된 상태이므로 idx++로 바로 넘어간다.)
		2-3. 이때 idx가 min_dist.size()를 넘으면 안된다.
10. 최종 결과인 `dp[d]`를 출력한다.

*/