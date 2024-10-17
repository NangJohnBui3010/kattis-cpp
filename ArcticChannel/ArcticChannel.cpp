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

struct point{
    int x,y;
};

struct edge{
    int p1,p2;
    double dist;
};

double distance(point a, point b){
    return(sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)));
}

bool cmp(edge a, edge b){
    return(a.dist < b.dist);
}

int findSet(vector<int> &DS, int a){
    if(DS[a] == -1)
        return a;
    DS[a] = findSet(DS, DS[a]);
    return DS[a];
}

void join(vector<int> &DS, int a, int b){
    a = findSet(DS,a);
    b = findSet(DS,b);
    if(a == b){
        return;
    }
    DS[a] = b;
}

int main(){ 
    int S,n,t;
    cin >> t;
    while(t--){
        cin >> S >> n;
        vector<point> arr(n);
        vector<int> DS(n,-1);
        for(int i = 0; i < n; i++){
            cin >> arr[i].x >> arr[i].y;
        }
        vector<edge> E;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                E.push_back({i,j,distance(arr[i],arr[j])});
            }
        }
        sort(E.begin(),E.end(),cmp);

        vector<double> resDist;

        for(int i = 0; i < E.size(); i++){
            if(findSet(DS, E[i].p1) != findSet(DS,E[i].p2)){
                join(DS,E[i].p1, E[i].p2);
                resDist.push_back(E[i].dist);
            }
        }

        for(int i = 1; i < S; i++)
            resDist.pop_back();
        cout.precision(2);
        cout << fixed << resDist.back() << endl;
    }
} 