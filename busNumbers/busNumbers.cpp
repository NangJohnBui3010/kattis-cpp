#include <iostream>
#include <set>
using namespace std;

int main(){
    int n;
    cin >> n;
    set<int> m;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        m.insert(a);
    }
    if(n == 1)
        cout << *m.begin() << endl;
    else{
        auto l = m.begin(), r = l; r++;
        while(r != m.end()){
            if(*r == *l + 1)
                r++;
            else{
                if(r - l == 1)
                    cout << *l << " " << *r;
            }
        }   
    }
    return 0;
}