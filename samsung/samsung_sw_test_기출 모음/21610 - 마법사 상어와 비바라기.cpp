#include<iostream>
using namespace std;
int dy[8] = {0,-1,-1,-1,0,1,1,1};
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int map[100][100];
int cloud[100][100];
int main(void){
    // 영역 입력
    // 방향, 크기 입력
    // 1. (N,1), (N,2), (N-1,1), (N-1,2)에 존재하는 구름을 d_i방향으로 s_i만큼 이동
    // M번 루프
    /*
    2. 도착칸에 물++
    3. 각 칸마다 루프 4번 돌려서 대각선의 좌표값이 둘 다 N보다 작고 물바구니에 물이 있으면 중심좌표 물바구니에 그만큼 물 더함
    4. 구름은 사라지고 그 위치 구름 사라진거 기억해둠.
    5. 전체 루프 돌면서 물바구니>=2이면 구름이 생성되고 -2
    6. 1번부터 반복
    */
    int n,m;
    int tot_wt=0;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    cloud[n-1][0]=1;
    cloud[n-1][1]=1;
    cloud[n-2][0]=1;
    cloud[n-2][1]=1;
    while(m--){
        int inc_wt[100][100]={0};
        int d,s;
        cin >> d >> s;
        // 1. 구름을 d_i방향으로 s_i만큼 이동 + 물 증가 + 구름 삭제
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(cloud[i][j]==1){
                    int y_c = (i+(s*dy[d-1]%n)+n)%n;
                    int x_c = (j+(s*dx[d-1]%n)+n)%n;
                    cloud[i][j]=0; // 기존 구름이 이동함.
                    inc_wt[y_c][x_c]=1; // 물 증가 칸 마킹.
                    map[y_c][x_c]++; // 물 증가
                }
            }
        }
        // 2. 각 칸마다 루프 4번 돌려서 대각선의 좌표값이 둘 다 N보다 작고 그 칸에 물이 있으면 중심좌표(r,c)에 그만큼 물 더함
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(inc_wt[i][j]==1){
                    int fd_wt_cnt=0;
                    for(int k=1; k<=4; k++){
                        int y_fd_wt = i+dy[k*2-1];
                        int x_fd_wt = j+dx[k*2-1];
                        if((0<=y_fd_wt && y_fd_wt<n) && (0<=x_fd_wt && x_fd_wt<n) && map[y_fd_wt][x_fd_wt]>=1){
                            fd_wt_cnt++;
                        }
                    }
                    map[i][j] += fd_wt_cnt;
                }
            }
        }
        // 3. 전체 루프 돌면서 (구름 아니였음 && 물바구니>=2)이면 구름이 생성되고 -2
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(inc_wt[i][j]!=1 && map[i][j]>=2){
                    map[i][j] -= 2;
                    cloud[i][j]=1;
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tot_wt += map[i][j];
        }
    }
    cout << tot_wt;
    return 0;
}