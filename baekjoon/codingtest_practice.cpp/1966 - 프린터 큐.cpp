#include<iostream>
#include<queue>
using namespace std;
int main(void){
    int t,n,m,p;
    cin >> t;
    while(t--){
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        int cnt=0;
        cin >> n >> m;
        for(int i=0; i<n; i++){
            cin >> p;
            q.push({p,i});
            pq.push(p);
        }
        while(!q.empty()){
            int f_1 = q.front().first;
            int f_2 = q.front().second;
            int max_pq = pq.top();
            if(!q.empty() && f_1 < max_pq){
                q.pop();
                q.push({f_1,f_2});
            } else if(!q.empty() && f_1 == max_pq) {
                q.pop();
                pq.pop();
                cnt++;
                if(f_2 == m){break;}
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}