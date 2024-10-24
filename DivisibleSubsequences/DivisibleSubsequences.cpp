#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int solve(vector<long long> &arr, int n, int d){
    vector<long long> pSum(n+1);
    unordered_map<int,int> mp;
    int count = 0; 
    pSum[1] = arr[1];
    mp[pSum[1] % d]++;
    for(int i = 2; i <= n; i++){
        pSum[i] = pSum[i-1] + arr[i];
        if(mp[pSum[i] % d] != 0){
            count += mp[pSum[i] % d];
        }
        mp[pSum[i] % d]++;
    }
    return count + mp[0];
}

vector<long long> arr(50001);
int main(){
    int n,c,d;
    cin >> c;
    while(c--){
        cin >> d >> n;
        for(int i = 1; i <= n; i++)
            cin >> arr[i];
        cout << solve(arr,n,d) << endl;
    }
    return 0;
}