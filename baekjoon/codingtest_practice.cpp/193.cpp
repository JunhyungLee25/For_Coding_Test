#include<iostream>
#include<algorithm>
using namespace std;
int N;
struct TIME{
    int st,ed;
    bool operator<(TIME& t){
        if (ed != t.ed) return ed < t.ed; // 정렬하게 되면 끝나는 순서 순으로
        return st < t.st; // 끝나는 시간이 같다면 시작하는 순서 순으로
    }
};
TIME t[100001];
int total=0;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;

    for(int i=0; i<N; i++){cin >> t[i].st >> t[i].ed;}
    sort(t,t+N);
    int cur_ed = 0;
    for(int i=0; i<N; i++){
        if(t[i].st < cur_ed) continue;
        cur_ed = t[i].ed;
        total++;
    }
    cout << total;
    return 0;
}