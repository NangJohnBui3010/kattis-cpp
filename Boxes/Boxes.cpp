#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int n;
vector<vector<int>> G;

int BFS(vector<int> &query){
    vector<bool> visited(n+1,0);
    int res = 0;
    queue<int> Q;
    for(auto x : query){
        Q.push(x);
        visited[x] = 1;
    }
    while(!Q.empty()){
        res ++;
        int v = Q.front(); Q.pop();
        for(auto x:G[v]){
            if(!visited[x])Q.push(x);
        }
    }
    return res;
}

vector<int> split(string s){
    vector<int> res;
    stringstream ss(s);
    string word;
    while(ss >> word){
        res.push_back(stoi(word));
    }
    return res;
}

int main(){
    int t;
    cin >> n; cin.ignore();
    G.resize(n+1);
    string s;
    getline(cin,s);
    vector<int> data = split(s);
    for(int i = 0; i < data.size(); i++){
        if(data[i] != 0)
            G[data[i]].push_back(i+1);
    }
    cin >> t;
    while(t--){
        int m;
        cin >> m;
        vector<int> query;
        while(m--){
            int temp; cin >> temp;
            query.push_back(temp);
        }
        cout << BFS(query) << endl;
    }
    return 0;
}