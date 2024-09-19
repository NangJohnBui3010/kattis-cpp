#include <iostream>
#include <string>
using namespace std;

int n,s,m, arr[201];
bool maps[201];
string fate(int x){
    if(x <= 0)
        return "left";
    else if(x > n)
        return "right";
    else if(arr[x] == m)
        return "magic";
    else if(maps[x])
        return "cycle";
    return "s";
}
int main(){
    int count = 0;
    cin >> n >> s >> m;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    while(fate(s) == "s"){
        maps[s] = true;
        s += arr[s];
        count ++;
    }
    cout << fate(s) <<"\n" << count;
    return 0;
}