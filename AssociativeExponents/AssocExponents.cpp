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
const int m = 1e9+7;
 
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main(){ 
    long long a,b,c;
    cin >> a >> b >> c;
    long long s1 = binpow(a, binpow(b,c,m),m);
    long long s2 = binpow(binpow(a,b,m),c,m);
    if(s1 != s2)
        cout << "Oh look, a squirrel!";
    else   
        cout << "What an excellent example!";
    return 0; 
} 