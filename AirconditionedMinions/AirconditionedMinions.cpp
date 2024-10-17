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

bool cmp(pair<int,int> a, pair<int,int> b){
    return(a.second < b.second);
}

int main(){ 
    int n; 
    cin >> n;
    vector<pair<int,int>> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end(), cmp);
    int res = 1, currRoom = arr[0].second;
    for(int i = 1; i < n; i++){
        if(arr[i].first > currRoom){
            currRoom = arr[i].second;
            res++;
        }
    }
    cout << res;
    return 0;
} 