// odd number select : total - odd*2 / even number select : total + even*2 
// 1 <= N <= 2*10^9 / 1 <= stage <= 300,000
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    long long N;
    int stage;
    int sel_num;
    while(T--){
        cin >> N >> stage;
        long long advangtageScore = (N & 1 ? ((N >> 1)+ 1) : (-(N >> 1)));
        unordered_map<int,bool> selected_num;
        selected_num.reserve(stage-1);

        vector<long long> results;
        results.reserve(stage);
        // 수정 : 중간 결과들을 저장하여 for문이 끝난 후 출력.
        // stage별 유리도
        for(int j=0; j<stage-1; j++){
            cin >> sel_num;
            results.push_back(advangtageScore);

            bool team1;
            auto find_num = selected_num.find(sel_num);
            if(find_num == selected_num.end()){team1 = (sel_num & 1);}
            else{team1 = find_num -> second;}
            
            if(team1){advangtageScore -= ((long long)sel_num << 1);}
            else {advangtageScore += ((long long)sel_num << 1);}

            selected_num[sel_num] = !team1;
        }
        results.push_back(advangtageScore); // 마지막 결과

        for(int k=0; k<results.size(); k++){
            cout << results[k] <<' ';
        }
        
        cout << '\n';
    } 
    return 0;
}