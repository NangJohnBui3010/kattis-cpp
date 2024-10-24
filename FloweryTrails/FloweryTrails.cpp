#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <set>
#include <unordered_map>

using namespace std;
const long long INF = 1000000000000;

typedef pair<int,int> pii;

int n,m;
vector<vector<pii>> G;
vector<long long> dist;
vector<long long> cost;
//vector<int> parent;

long long dijstrka(int start, int last){
    dist.resize(n+1); fill(dist.begin(), dist.end(), INF);
    cost.resize(n+1); fill(cost.begin(), cost.end(), 0);
    vector<unordered_map<int,int>>parent(n+1);
    int count = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> visited(n+1,0);
    dist[start] = 0;
    pq.push({0, start});    //first = distance, second = label

    while(!pq.empty()){
        int u = pq.top().second;    //Getting the label
        pq.pop();

        visited[u] = true;
        for(auto x : G[u]){
            int v = x.first;
            int weight = x.second;
            if(!visited[v]){
                if(dist[v] > dist[u] + weight){
                    parent[v].clear();
                    parent[v][u] = cost[u] + weight;
                    dist[v] = dist[u] + weight;
                    cost[v] = cost[u] + weight;
                    pq.push({dist[v],v});
                }
                else if(dist[v] == dist[u] + weight){
                    cost[v] += weight;
                }
                //parent[v] = u;
            }
        }
    }
    return cost[last];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    G.resize(n+1);
    for(int i = 1; i <= m; i++){
        int a,b,w;
        cin >> a >> b >> w;
        G[a].push_back({b,w});
        G[b].push_back({a,w});
    }
    cout << dijstrka(0,n-1)*2;
    return 0;
}