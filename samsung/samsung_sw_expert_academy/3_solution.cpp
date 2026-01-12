#include<vector>
#include<unordered_map>
#include<set>
#include<deque>
#include<algorithm>
using namespace std;
struct RESULT{
    int cnt;
    int IDs[5];
};
struct USER{
    int user_id;
    unordered_map<int,int> watch_list;
    vector<int> history; // history에 영화 시청 순서대로 모두 저장 
};
static vector<USER> users;
struct MOVIE{
    int movie_id;
    int genre;
    int total_score;
    int reg_order;
};
static deque<MOVIE> real_movies; // 실제 영화 
auto cmp = [](const MOVIE *a, const MOVIE *b){
    if(a->total_score != b->total_score) return a->total_score > b->total_score;
    return a->reg_order > b->reg_order;
};
static int reg_order_is; // 영화 등록 순번
static unordered_map<int,int> id2idx; // 영화 id를 이용해 실제 영화 vector의 idx를 빠르게 찾기 위한 map
static multiset<MOVIE*, decltype(cmp)> all_movies_list(cmp); // 전체 영화 저장
static multiset<MOVIE*, decltype(cmp)> genre_list[6] = { // 장르별 리스트(인덱스 1~5만 사용)
    multiset<MOVIE*, decltype(cmp)>(cmp), multiset<MOVIE*, decltype(cmp)>(cmp),
    multiset<MOVIE*, decltype(cmp)>(cmp), multiset<MOVIE*, decltype(cmp)>(cmp),
    multiset<MOVIE*, decltype(cmp)>(cmp), multiset<MOVIE*, decltype(cmp)>(cmp)
};
void init(int N){
    users.clear();
    users.resize(N + 1);
    real_movies.clear();
    id2idx.clear();
    all_movies_list.clear();
    for(int i=1; i<=5; i++){
        genre_list[i].clear();
    }
    reg_order_is = 0;
    for(int i=1; i<=N; i++){users[i].user_id = i;}
}
int add(int mID, int mGenre, int mTotal){
    if(id2idx.count(mID)) return 0; // 중복 확인
    // 영화 등록
    MOVIE m_reg;
    m_reg.movie_id = mID;
    m_reg.genre = mGenre;
    m_reg.total_score = mTotal;
    m_reg.reg_order = reg_order_is++;
    
    real_movies.push_back(m_reg);
    int idx = (int)real_movies.size()-1; 
    id2idx[mID] = idx;
    
    // 전체 영화 리스트, 장르별 리스트 삽입
    MOVIE *m_insert = &real_movies[idx];
    all_movies_list.insert(m_insert);
    genre_list[mGenre].insert(m_insert);

    return 1;
}
// 수정 : erase 동작시 사용자의 기록은 완전히 삭제하지 않음. 
int erase(int mID){
    // 1. 등록된 영화인지 확인
    if(!id2idx.count(mID)){return 0;}

    // 2. 리스트에서 영화 제거
    int idx = id2idx[mID];
    MOVIE* m_erase = &real_movies[idx];

    auto er = all_movies_list.find(m_erase);
    if(er != all_movies_list.end()) all_movies_list.erase(er);

    auto &g_set = genre_list[m_erase->genre];
    auto g_er = g_set.find(m_erase);
    if(g_er != g_set.end()) g_set.erase(g_er);
    
    id2idx.erase(mID);

    // 3. deque에서 완전히 제거
    int last_idx = (int)real_movies.size() - 1;
    if(last_idx != idx){
        MOVIE last_movie = real_movies[last_idx]; 
        MOVIE *last_ptr = &real_movies[last_idx];

        auto er = all_movies_list.find(last_ptr);
        if(er != all_movies_list.end()) all_movies_list.erase(er);
        
        auto &g_set = genre_list[last_ptr->genre];
        auto g_er = g_set.find(last_ptr);
        if(g_er != g_set.end()) g_set.erase(g_er);

        real_movies[idx] = last_movie;
        id2idx[last_movie.movie_id] = idx;
        
        MOVIE* new_ptr = &real_movies[idx];
        all_movies_list.insert(new_ptr);
        genre_list[new_ptr->genre].insert(new_ptr);
    }
    real_movies.pop_back();
   
    return 1;
}
// 수정 : 5개 제한을 없애고 모든 기록을 순서대로 저장.
int watch(int uID, int mID, int mRating){
    // 등록되지 않은 영화이거나 이미 봤던 영화면 return 0
    if(id2idx.count(mID) == 0 || users[uID].watch_list.count(mID)) return 0;
    
    // 시청 기록 저장
    users[uID].watch_list[mID]=mRating;
    users[uID].history.push_back(mID);

    // 영화 총점 업데이트 및 리스트 갱신 
    int idx = id2idx[mID];
    MOVIE* m_renew = &real_movies[idx];
    // 1. 삭제
    auto er = all_movies_list.find(m_renew);
    if(er != all_movies_list.end()) all_movies_list.erase(er);
    
    auto &g_set = genre_list[m_renew->genre];
    auto g_er = g_set.find(m_renew);
    if(g_er != g_set.end()) g_set.erase(g_er);
    // 2. 실제 영화 총점 업데이트
    m_renew->total_score += mRating;
    // 3. 업데이트된 영화 정보 리스트에 삽입
    all_movies_list.insert(m_renew);
    genre_list[m_renew->genre].insert(m_renew);

    return 1;
}

RESULT suggest(int uID){
    RESULT res{0,{0}};
    res.cnt = 0;

    vector<int> valid_history;
    for(int i = users[uID].history.size()-1; i>=0; i--){
        int mID = users[uID].history[i];
        if(id2idx.count(mID)){
            valid_history.push_back(mID);
            if(valid_history.size() == 5) break;
        }
    }
    int suggest_genre = -1;
    // 유효한 시청기록 존재
    if(!valid_history.empty()){
        int best_rating = -1;
        int target_mID = -1;
        reverse(valid_history.begin(), valid_history.end());

        for(int mID : valid_history){
            int user_rate = users[uID].watch_list[mID];
            if(user_rate >= best_rating){
                best_rating = user_rate;
                target_mID = mID;
            }
        }
        suggest_genre = real_movies[id2idx[target_mID]].genre;
    }

    if(suggest_genre != -1){
        for(auto i=genre_list[suggest_genre].begin(); i != genre_list[suggest_genre].end() && res.cnt < 5; i++){
            MOVIE *m = *i;
            if(users[uID].watch_list.count(m->movie_id)) continue;
            res.IDs[res.cnt++] = m->movie_id;
        }
    }
    else {
        for(auto i=all_movies_list.begin(); i != all_movies_list.end() && res.cnt < 5; i++){
            MOVIE *m = *i;
            if(users[uID].watch_list.count(m->movie_id)) continue;
            res.IDs[res.cnt++] = m->movie_id;
        }
    }
    return res;
}