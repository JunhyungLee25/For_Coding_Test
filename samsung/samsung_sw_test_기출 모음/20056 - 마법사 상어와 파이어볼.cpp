#include <iostream>
#include <vector>
using namespace std;
int n,m,k;
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int dx[8] = {0,1,1,1,0,-1,-1,-1};
struct fireball{
    int y,x,m,s,d;
};
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    vector<fireball> fb;
    // input
    for(int i=0; i<m; i++){
        int y,x,m,d,s;
        cin >> y >> x >> m >> s >> d;
        fb.push_back({y-1,x-1,m,s,d});
    }
    // body
    for(int i=0; i<k; i++){
        vector<int> map[51][51];
        // step 1
        for(int j=0; j<fb.size(); j++){
            int ny = ((fb[j].y+(dy[fb[j].d]*fb[j].s%n))+n)%n;
            int nx = ((fb[j].x+(dx[fb[j].d]*fb[j].s%n))+n)%n;    
            map[ny][nx].push_back(j);          
        }
        // step 2
        vector<fireball> nx_fb;
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                if(map[r][c].size()==0) continue;
                else if(map[r][c].size()==1) {
                    fireball curr = fb[map[r][c][0]];
                    nx_fb.push_back({r,c,curr.m,curr.s,curr.d});
                }
                else {
                   int m_val=0,d_val=0,s_val=0,d_cnt=0;
                    for(int j=0; j<map[r][c].size(); j++){
                        m_val += fb[map[r][c][j]].m;
                        s_val += fb[map[r][c][j]].s;
                        if(fb[map[r][c][j]].d%2==0){
                            d_cnt++;
                        }
                    }
                    int m_res = m_val/5;
                    int s_res = s_val/map[r][c].size();
                    if(m_res == 0) continue;
                    if(d_cnt == map[r][c].size() || d_cnt==0){
                        for(int dir=0; dir<4; dir++){
                            nx_fb.push_back({r,c,m_res,s_res,dir*2});
                        }
                    } else {
                        for(int dir=0; dir<4; dir++){
                            nx_fb.push_back({r,c,m_res,s_res,dir*2+1});
                        }
                    }
                }
            }
        }
        // step 3
        fb = nx_fb;
    }
    int total_m = 0;
    for(int f=0; f<fb.size(); f++){
        total_m += fb[f].m;
    }
    cout << total_m;
    return 0;
}