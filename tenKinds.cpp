#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dRow[] = {1,0,-1,0};
int dCol[] = {0,1,0,-1};
int r, c, nComp = 0;

bool validSquare(int y, int x){
    return(y >= 0 && y < r && x >= 0 && x < c);
}

void BFS(vector<vector<int>> m, vector<vector<int>> &comp, int y, int x){
    queue<pair<int,int>> Q;
    Q.push({y,x});
    comp[y][x] = ++nComp;
    while(!Q.empty()){
        int curY = Q.front().first, curX = Q.front().second;
        for(int i = 0; i < 4; i++){
            int cY = curY;
            int cX = curX;
            cY += dRow[i]; cX += dCol[i];
            if(validSquare(cY,cX) && comp[cY][cX] == 0 && m[curY][curX] == m[cY][cX]){
                comp[cY][cX] = comp[curY][curX];
                Q.push({cY,cX});
            }
        }
        Q.pop();
    }
}

int main(){
    cin >> r >> c;
    vector<vector<int>> m(r, vector<int>(c));
    vector<vector<int>> comp(r, vector<int>(c, 0));
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
            {
                char a;
                cin >> a;
                m[i][j] = (a=='1')?1:0;
            }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(comp[i][j] == 0)
                BFS(m,comp,i,j);
        }
    }

    int q = 0;
    cin >> q;
    for(int i = 0; i < q; i++){
        int x1,y1,x2,y2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--; x1--; y2--; x2--;
        if(comp[y1][x1] == comp[y2][x2])
        {
            if(m[y1][x1] == 1)cout << "decimal" << endl;
            else cout << "binary" << endl;
        }else cout << "neither" << endl;
    }
    return 0;
}