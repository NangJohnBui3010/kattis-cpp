#include <iostream>
#include <set>
#include <iterator>

using namespace std;
int n,q;
multiset<int> m;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> n >> q;
    multiset<int>::iterator itr;
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        m.insert(a);
    }
    for(int i = 0; i < q; i++){
        int t; cin >> t;
        int d; cin >> d;
        int temp;
        if(t == 1)
            itr = m.upper_bound(d);
        else{
            itr = m.upper_bound(d);
            itr--;
            if(itr == m.end() || *itr > d)
                itr = m.end();
        }
            
        if(itr != m.end())
        {
            cout << *itr << endl;
            m.erase(itr);
        }
        else cout << -1 << endl;
    }
    return 0;
}