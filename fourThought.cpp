#include <iostream>
#include <vector>
#include <string>
using namespace std;

char ops[] = {'*','-','+','/'};

bool validString(string s, int target){
    //check for * and /
    int res = 4;
    vector<int> m;
    int l = 0;
    m.push_back(4);

    for(int i = 2; i < 14; i+=4){
        if(s[i] == '*')
            m[l] *= (s[i+2]-'0');
        else if(s[i] == '/')
            m[l] /= (s[i+2]-'0');
        else{
            if(s[i] == '-')m.push_back(-4);
            else m.push_back(4);
            l++;
        }
    }
    
    int sum = 0;
    for(int i = 0; i < m.size(); i++)
        sum += m[i];
    return sum == target;
}

string Solve(int n){
    //operation id = 2,5,8
    string res = "4   4   4   4 = "+ to_string(n);
    for(int i = 0; i < 4; i++){
        res[2] = ops[i];
        for(int j = 0; j < 4; j++){
            res[6] = ops[j];
            for(int k = 0; k < 4; k++){
                res[10] = ops[k];
                if(validString(res,n))
                    return res;
            }
        }
    }
    return "no solution";
}

int main(){
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int n;
        cin >> n;
        cout << Solve(n) << endl;
    }
    return 0;
}