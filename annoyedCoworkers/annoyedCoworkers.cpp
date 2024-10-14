#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL); cout.tie(NULL);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    int h,c;
    ll res = 0;
    cin >> h >> c;
    for(int i = 0; i < c; i++){
        int a,d;
        cin >> a >> d;
        res = max((ll)a,res);
        pq.push({a+d,d});
    }

    while(h && !pq.empty()){
        pair<ll,ll> curr = pq.top(); pq.pop();
        res = max(res,curr.first);
        pq.push({curr.first+curr.second, curr.second});
        h--;
    }
    cout << res;
    return 0;
}
