/*
전체 사람 수: N
촌수 계산해야 될 두 사람: A B

x y
x: y의 부모

1 | 2 3
2 | 1 8 9
3 | 1
4 | 5 6
5 | 4
6 | 4
7 | 2
8 | 2

1 | 2 3
2 | 7 8 9
4 | 5 7


7 3중에 더 작은 3으로 시작.
3과 1촌인 촌수[people[3][0]] = cnt
7 만날 때 까지
전체 다 돌아도 없으면 -1 출력
BFS
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N,A,B,R;
int cnt;
vector<vector<int>> people;
int relationship[101];
bool visited[101];

void BFS(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()){
        int k = q.front();
        q.pop();

        for(int i=0; i<people[k].size(); i++){
            if(visited[people[k][i]]==false){
                q.push(people[k][i]);
                relationship[people[k][i]] = relationship[k]+1;
                visited[people[k][i]] = true;
            }
        }
    }
}

int main(void){
    cin >> N >> A >> B >> R;
    int x,y;
    people.resize(N+1);
    for(int i=0; i<R; i++){
        cin >> x >> y;
        people[x].push_back(y);
        people[y].push_back(x);
    }
    BFS(A);
    if(A==B) cout << 0;
    else if(relationship[B]==0) cout << -1;
    else cout << relationship[B];
    return 0;
}