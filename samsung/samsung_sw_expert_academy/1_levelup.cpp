// 3 <= N <= 100,000 / -5,000 <= X_i <= 5,000 
#include<iostream>
#include<cstdlib>
#define MAX 100000
using namespace std;
int route[MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T,N;
    int i,j;
    int d1,d2,d3;
    cin >> T; // test case
    while(T--){
        int max_d = -1;
        int min_distance = 0;
        int total_distance=0;
        cin >> N; // check point
        for(j=0; j<N; j++){cin >> route[j];} // X
        // 1. 전체 이동거리 계산
        for(j=0; j<N-1; j++){total_distance += abs(route[j+1]-route[j]);}
        // 2. 중간 지점을 생략했을 때 얻어지는 최소 거리 계산
        for(j=0; j<N-2; j++){
            d1 = abs(route[j+1] - route[j]);
            d2 = abs(route[j+2] - route[j+1]);
            d3 = abs(route[j+2] - route[j]);
            if(max_d < d1 + d2 - d3){
                max_d = d1 + d2 - d3;
            }
        }
        
        cout << total_distance - max_d << '\n';
    }
    return 0;
}