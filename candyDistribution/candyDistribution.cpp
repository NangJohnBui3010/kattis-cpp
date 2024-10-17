#include <iostream>
#include <cmath>
using namespace std;

int extended_euclidean(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int mod_inverse(int a, int m){
    int x, y;
    int g = extended_euclidean(a, m, x, y);
    if (g != 1) {
        return -1;
    }
    x = (x % m + m) % m;
    return x;
}

int main(){
    int t;
    //cin >> t;
    //for(int i = 0; i < t; i++){
        int k,c;
        cin >> k >> c;
        int res = mod_inverse(k,c);
        if(res == -1)
            cout << "IMPOSSIBLE" << endl;
        else   
            cout << res << endl;
    //}
    return 0;
}