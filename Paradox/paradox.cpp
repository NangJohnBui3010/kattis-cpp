#include <iostream>
#include <vector>
using namespace std;


bool FindPath(pair<int,int> Start,
                pair<int,int> End,
                const vector<int> &Map,
                pair<int,int> MapDimensions,
                vector<int> &OutPath){

    int r = MapDimensions.second; //row
    int c = MapDimensions.first; //column
    //converting 1-D map to 2-D array
    vector<vector<int>> m(MapDimensions.second, vector<int>(MapDimensions.first));
    int l = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            m[i][j] = Map[l];
            l++;
        }
    }
}
int main(){
    return 0;
}