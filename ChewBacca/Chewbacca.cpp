#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, k, Q;

int solve(ll x, ll y, ll k) {
    int res = 0;
    while (x != y) {
        if (x < y) 
            y = floor((y - 1) / k);
        else 
            x = floor((x - 1) / k);
        res++;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k >> Q;
    while (Q--) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        cout << solve(x, y, k)<< endl;
    }
    return 0;
}
