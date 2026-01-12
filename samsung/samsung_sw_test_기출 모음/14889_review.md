# review

실수했던 부분:
1. i,index 역할 혼동: 
	$N$명 중 $N/2$명을 뽑아야 하는데, 재귀 함수의 매개변수와 반복문 변수를 혼동하였다.
    
- **실수 코드:**
    
```c++
// 반복문 변수는 i인데, 고정된 index를 사용하여 상태를 변경함
for(int i = index; i < n; i++) {
	start[index] = true;      // ERROR: i가 아니라 index를 true로 바꿈
	select_team(cnt + 1, index + 1); 
	// ERROR: 현재 선택한 i의 다음 사람이 아닌, index 다음을 호출
}
```
    
- **문제점:** 선택된 사람 다음 사람을 탐색하는 것이 아니라, 계속 제자리걸음을 하거나 중복된 사람을 선택하게 됨.
    

2. 점수 계산 시 중복 누적:
    
- **실수 코드:**
    
```c++
if(temp_team[i] && temp_team[j]) {
	// 이미 i, j가 0~N까지 도는데, 여기서 대칭 합을 또 구함
	temp1 += team[i][j] + team[j][i]; 
}
```
    
- **문제점:** 반복문이 `(1, 2)`일 때 `S12 + S21`을 더하고, 나중에 `(2, 1)`일 때 또 `S21 + S12`를 더하게 되어 결과값이 실제보다 2배 뻥튀기됨.

동작 방식:
함수 2개를 사용하여 구현하였다.
1. 각 팀의 능력치 합을 얻고 차를 계산하는 함수
	1. start팀의 점수와 link팀의 점수를 합산하는 변수 선언
	2. temp_team 배열에서 true이면 start팀 false이면 link팀이므로 참&참이면 start팀에 `team[i][j]`만큼 점수 추가 거짓&거짓이면 link팀에 `team[i][j]`만큼 점수 추가.
	3. start팀과 link팀의 점수차를 반환한다.
2. 조합을 만들어 주는 함수
	1. N/2 만큼 팀원 선택되면 각 팀 총점의 차를 구해야 하므로 `cnt==N/2`가 terminate 조건이다.
		- terminate조건이 참이면 각 팀의 점수를 구하는 함수 호출
		- 각 팀 점수의 차가 현재 최소값보다 작으면 최소값 갱신
	2. 선택하면 cnt, index 증가하고 다음 단계로 넘어간다.
	3. for loop를 이용하여 중복된 값 선택 방지
	4. terminate 조건문에서 return 되면 다른 조합을 얻어야 하므로 현재 단계에서 선택했던 index 해제를 해주어야 한다.



```c++
#include<iostream>
using namespace std;
int n;
int min_result=1000000;
int team[20][20];
bool selected[20];
int min_team(){
    int start_score=0;
    int link_score=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(selected[i] && selected[j]){
                start_score += team[i][j];
            }
            if(!selected[i] && !selected[j]){
                link_score += team[i][j];
            }
        }
    }
    if(start_score > link_score){return start_score-link_score;}
    else{return link_score-start_score;}
}
void select_team(int cnt, int index){
    if(cnt == n/2){
        int min_temp = min_team();
        if(min_temp < min_result){
            min_result = min_temp;
        }
        return;
    }
    for(int i=index; i<n; i++){
        selected[i] = true;
        select_team(cnt+1,i+1);
        selected[i] = false;
    }
}
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> team[i][j];
        }
    }
    select_team(0,0);
    cout << min_result;
    return 0;
}
```