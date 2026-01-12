#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Cell{
    int x;
    int y;
};

bool CompareXY(const Cell &a, const Cell &b){
    if(a.y == b.y){
        return a.x < b.x;
    }
    return a.y < b.y;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<Cell> s(N);
    for(int i=0; i<N; i++){
        cin >> s[i].x >> s[i].y;
    }
    sort(s.begin(),s.end(), CompareXY);
    for(int i=0; i<N; i++){
        cout << s[i].x << " " << s[i].y << '\n';
    }
}