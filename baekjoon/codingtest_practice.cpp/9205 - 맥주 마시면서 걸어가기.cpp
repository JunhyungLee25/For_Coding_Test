#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;

int t,n,y,x;

int main(void){
    cin >> t;
    while(t--){
        bool flag = false;
        cin >> n;
        queue<int> q;
        vector<pair<int, int>> store;
        vector<bool> visited(n+2, false);
        
        for(int i=0; i<n+2; i++){
            cin >> y >> x;
            store.push_back({y,x});
        }

        q.push(0);
        visited[0] = true;
    
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(curr == n+1){
                flag = true;
                break;
            }
            for(int i=1; i<n+2; i++){
                if(!visited[i]){
                    int dist = abs(store[curr].first - store[i].first) + abs(store[curr].second -  store[i].second);
                    if(dist<=1000){
                        visited[i]=true;
                        q.push(i);
                    }
                }
            }        
        }
        if(flag) cout << "happy" << '\n';
        else cout << "sad" << '\n'; 
    }
    return 0;
}
