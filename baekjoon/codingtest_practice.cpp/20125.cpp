#include<iostream>
using namespace std;
string cookie[1000];
int n,h_y,h_x;
int l_arm,r_arm,body,l_leg,r_leg;
void cookie_spec(){
    for(int x=1; x<n; x++){
        if(h_x-x>=0 && cookie[h_y][h_x-x] == '*'){
            l_arm++;
        }
        if(h_x+x<n && cookie[h_y][h_x+x] == '*'){
            r_arm++;
        }
    }
    for(int y=h_y; y<n; y++){
        if(cookie[y+1][h_x] == '*'){
            body++;
        } else {break;}
    }
    for(int y=h_y+body+1; y<n; y++){
        if(cookie[y][h_x-1] == '*'){
            l_leg++;
        }
        if(cookie[y][h_x+1] == '*'){
            r_leg++;
        }
    }
    cout << h_y+1 << ' ' << h_x+1 << '\n';
    cout << l_arm << ' ' << r_arm << ' ' << body << ' ' << l_leg << ' ' << r_leg;
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> cookie[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(cookie[i][j] == '*'){
                h_y = i+1;
                h_x = j;
                cookie_spec();
                return 0;
            }
        }
    }
}