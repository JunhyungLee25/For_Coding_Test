#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
struct WORD{
    string word;
    int cnt;
    int len;
};
bool compare(const WORD &a, const WORD &b){
    if(a.cnt != b.cnt){
        return a.cnt > b.cnt;
    }

    if(a.len != b.len){
        return a.len > b.len;
    }
    return a.word < b.word;
}
vector<WORD> w;
unordered_map<string, int> wordnote;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    string wd;
    for(int i=0; i<n; i++){
        cin >> wd;
        if(wd.length()<m){
            continue;
        }
        if(wordnote.find(wd) == wordnote.end()){ // 해시맵에서 단어를 찾고 end를 반환했다면 찾지 못했다는 뜻.
            wordnote[wd] = w.size(); // 맵에 {단어: 현재 벡터의 크기} 기록
            WORD temp;
            temp.word = wd;
            temp.cnt = 1;
            temp.len = wd.length();
            w.push_back(temp);
        } else{ // 이미 존재하는 단어이면
            int index = wordnote[wd]; // 맵에서 그 단어가 벡터의 몇 번째에 있는지 가져옴.
            w[index].cnt++; 
        }
    }
    sort(w.begin(),w.end(),compare); // 정렬
    for(int i=0; i<w.size(); i++){
        cout << w[i].word << '\n';
    }

    return 0;
}