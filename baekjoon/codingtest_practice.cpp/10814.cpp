#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Online {
    int old;
    string name;
};

bool operator<(const Online &a, const Online &b) {
    return a.old < b.old;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<Online> s(N);
    for(int i=0; i<N; i++){
        cin >> s[i].old >> s[i].name;
    }
    stable_sort(s.begin(),s.end());
    for(int i=0; i<N; i++){
        cout << s[i].old << " " << s[i].name << '\n';
    }
    return 0;
}
