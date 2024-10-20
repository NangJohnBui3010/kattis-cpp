#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n, t;
    vector<int> arr;
    arr.push_back(0);
    cin >> n >> t;
    while(t--){
        int step;
        string s;
        cin >> s;
        int pos = arr.back();
        if(s != "undo"){
            step = stoi(s);
            //cout << "current position: " << pos << endl;
            //cout << "step: " << step << endl;
            if(step > 0){
                pos = (pos + step%n) % n;
                //cout << "positive pos: "<< pos << endl;
            }else{
                step = abs(step);
                step %= n;
                if(pos - step < 0){
                    pos = n-(step-pos);
                }else
                    pos-=step;
                //cout << "negative pos: "<< pos << endl;
            }
            arr.push_back(pos);
        }
        else{
            int temp; cin >> temp;
            //cout << "undo step: " << temp << endl;
            while(temp--)
                arr.pop_back();
            //cout << "pos: " << arr.back() << endl;
        }
        //cout << t << "---------------" << endl;
    }
    cout << arr.back();
    return 0;
}

//0 1 2 3 4 