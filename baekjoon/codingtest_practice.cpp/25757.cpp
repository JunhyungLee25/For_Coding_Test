#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,x;
    cin >> N;
    char a;
    cin >> a;
    if(a=='Y'){x=1;}
    else if(a=='F'){x=2;}
    else{x=3;}
    int p=0;
    set<string> players;
    string name;
    for(int i=0; i<N; i++){
        cin >> name;
        players.insert(name);
        p++;
    }
    cout << players.size()/x << '\n';
    return 0; 
}