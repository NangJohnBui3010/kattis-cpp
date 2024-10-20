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

struct duration{
    int h,m,s;
};

double toHour(duration x){
    double res = x.h + (double)x.m/60 + (double)x.s/3600;
    return res;
}

duration convert_to_duration(string s){
    duration res;
    stringstream ss(s);
    string word;
    getline(ss,word,':');
    res.h = stoi(word);
    getline(ss,word,':');
    res.m = stoi(word);
    getline(ss,word,':');
    res.s = stoi(word);
    return res;
}

vector<string> split(string s){
    stringstream ss(s);
    string word;
    vector<string> res;
    while(ss >> word){
        res.push_back(word);
    }
    return res;
}

int main(){ 
    string s;
    int speed;
    double dist = 0;
    cin >> s >> speed;
    duration prevTime = convert_to_duration(s);
    cin.ignore();
    while(getline(cin,s)){
        vector<string> data = split(s);
        duration currTime = convert_to_duration(data[0]);
        dist += speed*(toHour(currTime) - toHour(prevTime));
        prevTime = currTime;
        if(data.size() == 2)
            speed = stoi(data[1]);
        else{
            cout.precision(2);
            cout << fixed << s << " " << dist << " km\n";
        }
    }
    return 0; 
} 