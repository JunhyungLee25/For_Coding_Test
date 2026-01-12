#include<unordered_map>
#include<vector>
#include<cstring>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;

static unordered_map<int, unordered_map<int, bool>> user_setting; // key : userid -> key : groupid, value : user setting(on : true, off : false)
struct MESSAGE{
    string text;
    int from_group_id;
};
static unordered_map<int, deque<MESSAGE>> user_message; // key : userid, value : 받은 메시지
struct GROUP{
    vector<int> participants;
};
static unordered_map<int, GROUP> groups; // group id를 key로 사용.

void init(int N){
    user_setting.clear();
    groups.clear();
    user_message.clear();
}

void createGroup(int groupID, int mNum, int uIDs[]){
    // 1. 그룹 생성
    GROUP new_G;
    new_G.participants.assign(uIDs, uIDs + mNum);
    // 2. 초기 set 설정 : on
    for(int p_id : new_G.participants){user_setting[p_id][groupID] = true;}
    groups[groupID] = new_G;
}

int sendMessage(int uID, int groupID, char mText[]){
    int set_on_mem_cnt=0;
    // 1. group에 존재하는 멤버들중 set가 on인 멤버에게만 메시지 전송
    for(int p_id : groups[groupID].participants){
        if(p_id != uID && user_setting[p_id][groupID]){
            set_on_mem_cnt++;
            user_message[p_id].push_back({mText, groupID});
        }
    }
    // 2. 메시지를 받은 유저의 수를 return
	return set_on_mem_cnt;  
}

void setOnOff(int uID, int groupID){
    // 1. uID user의 groupID의 set을 토글
    user_setting[uID][groupID] = !user_setting[uID][groupID];
    // 2. uID user의 groupID에서 온 모든 메시지 삭제
    auto &messages = user_message[uID];
    auto remove_m = remove_if(messages.begin(), messages.end(), [groupID](const MESSAGE& m){
        return m.from_group_id == groupID;
    }
    );
    messages.erase(remove_m, messages.end());
}

int checkMsg(int uID, char mMsg[]){
    // 1. 받은 메시지 있는지 확인
    if(user_message[uID].empty()){return 0;}
    // 2. 삭제하기 전에 받은 메시지 개수 미리 저장
    int message_num = user_message[uID].size();
    // 3. 가장 최신 메시지 저장
    strcpy(mMsg, user_message[uID].back().text.c_str());
    // 4. 받은 모든 메시지 삭제
    user_message[uID].clear();
	return message_num; // 받은 메시지 개수 return
}