#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;

int string_to_number(const string& s) {
    if(s == "favourably")return 0;
    if(s == "catastrophically")return -1;
    int res = 0;
    for(int i = 0; i < s.length(); i++) {
        (res *= 10) += (s[i]-'0');
    }
    return res;
}

vector<int> breakString(string &s){
    vector<int> res;
    stringstream ss(s);
    string word;
    while(ss >> word)
        res.push_back(string_to_number(word));
    return res;
}

int dfs(const unordered_map<int, vector<int>>& m, int node, unordered_map<int, int>& memo) {
    if (memo.count(node)) return memo[node];
    
    int count = 0;
    for (int next : m.at(node)) {
        if (next == 0) count++;
        else if (next != -1) count += dfs(m, next, memo);
    }
    
    return memo[node] = count;
}

int countFavorableEndings(const unordered_map<int, vector<int>>& m, int section) {
    unordered_map<int, int> memo;
    return dfs(m, section, memo);
}

void Solve() {
    unordered_map<int, vector<int>> m;
    int s;
    cin >> s;
    cin.ignore();
    for (int i = 0; i < s; i++) {
        int id;
        cin >> id;
        string temp;
        getline(cin, temp);
        m[id] = breakString(temp);
    }
    cout << countFavorableEndings(m, 1) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("FAV.INP","r",stdin);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        Solve();
    }
}