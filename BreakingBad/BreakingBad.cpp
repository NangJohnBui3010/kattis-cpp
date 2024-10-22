#include <map>
#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

int n;
unordered_map<string,int> mp;
vector<string> itemName;
vector<vector<int>> G;
vector<string> jesse, walter;
vector<int> team;

void BFS(int x, bool &status){
    team[x] = 1;
    //cout << "team[" << x << "] = 1" << endl;
    queue<int> Q;
    Q.push(x);
    while(!Q.empty()){
        int v = Q.front(); Q.pop();
        //cout << " -------------------BFS " << v << endl;
        for(auto temp : G[v]){
            if(team[temp] == team[v]){
                status = 1;
                return;
            }else if(team[temp] == 0){
                team[temp] = -team[v];
                //cout << "team[" << temp <<"] = " << team[temp] << endl;
                Q.push(temp);
            }
        }
    }
}

int main(){
    cin >> n;
    G.resize(n+1);
    itemName.resize(n+1);
    team.resize(n+1);
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        mp[s] = i;
        itemName[i] = s;
    }

    int t;
    cin >> t;
    while(t--){
        string a,b; cin >> a >> b;
        int t1 = mp[a], t2 = mp[b];
        //cout << "item1 = " << t1 << " item2 = " << t2 << endl;
        G[t1].push_back(t2); G[t2].push_back(t1);
    }

    bool status = 0;
    for(int i = 1; i <= n; i++){
        if(team[i] == 0){
            BFS(i,status);
            if(status){
                cout << "impossible";
                return 0;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(team[i] == -1)
            jesse.push_back(itemName[i]);
        else
            walter.push_back(itemName[i]);
    }

    for(auto x:jesse) cout << x << " ";
    cout << endl;
    for(auto x:walter)cout << x << " ";
    return 0;
}