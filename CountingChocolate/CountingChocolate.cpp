#include <iostream> 
#include <cstring> 
#include <cmath> 
#include <algorithm> 
#include <climits> 
#include <stack> 
#include <queue> 
#include <vector> 
#include <set> 
#include <map> 
#include <list> 
#include <cassert> 
#include <unordered_map> 

#include <sstream> 

using namespace std; 

int main(){
    int n;
    cin >> n;
    vector<int> arr(n+1);
    vector<bool> dp(101,false);
    int maxN = 0;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        dp[arr[i]] = true;
        sum += arr[i];
    }
    dp[0] = 1;
    if(sum % 2 != 0)
    {
        cout << "NO";
        return 0;
    }

    sort(arr.begin(), arr.end());
    for(int i = 1; i <= sum/2; i++){
        for(int j = 1; j <= n; j++){
            if(i - arr[j] > 0)
                dp[i] = dp[i-arr[j]];
            else
                break;
        }
    }
    if(dp[sum/2]) cout << "YES";
    else cout << "NO";
    return 0; 
} 

 