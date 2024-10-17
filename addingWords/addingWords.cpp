#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>


using namespace std;

unordered_map<string,int> mp;

string handleCalc(string s){
    stringstream ss(s);
    string curr;
    vector<string> calcString;
    while(ss >> curr)
        calcString.push_back(curr);
    int ansNum = mp[calcString[0]];
    for(int i = 2; i <= calcString.size()-2; i+= 2){
        if(mp.find(calcString[i]) == mp.end())
            return "unknown";
        if(calcString[i-1] == "-")
            ansNum -= mp[calcString[i]];
        else
            ansNum += mp[calcString[i]];
    }
    for(auto x : mp){
        if(x.second == ansNum)
            return x.first;
    }
    return "unknown";
}

int main(){
    string command;
    while(cin >> command){
        if(command == "def"){
            string name; int value;
            cin >> name >> mp[name];
        }else if(command == "calc"){
            string calculation;
            cin.ignore();
            getline(cin, calculation);
            cout << calculation << " "<< handleCalc(calculation) << endl;
        }else{
            mp.clear();
        }
    }
    return 0;
}
