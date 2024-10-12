#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n,1);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(s[i] > s[j]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    cout << 26-*max_element(dp.begin(), dp.end());
    return 0;
}