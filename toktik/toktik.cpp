#include <unordered_map>
#include <iostream>

using namespace std;

int main(){
    unordered_map<string,int> m;
    int n;
    cin >> n;
    string res;
    for(int i = 0; i < n; i++){
        string temp;
        int views;
        cin >> temp >> views;
        m[temp] += views;
        if(i == 0)
            res = temp;
        else if(m[res] < m[temp])
            res = temp;
    }
    cout << res;
    return 0;
}