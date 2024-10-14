#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int numPrime(int n){
    int res = 0, i = 2;
    while (n % 2 == 0) 
    { 
        res++;
        n = n/2; 
    } 
 
    // n must be odd at this point. So we can skip 
    // one element (Note i = i +2) 
    for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 
        // While i divides n, print i and divide n 
        while (n % i == 0) 
        { 
            res++;
            n = n/i; 
        } 
    } 
    if (n > 2) res ++;
    if(res == 1)return 0;
    return res; 
}
int main(){
    int n; cin >> n;
    cout << numPrime(n);
    return 0;
}