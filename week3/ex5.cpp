#include<bits/stdc++.h>

using namespace std;

map<string, vector<string > > mp;

int descendants(string name){
    int res = 0;
    for (auto x : mp[name]){
        res += 1 + descendants(x);
    }
    return res;
}

int generation(string name){
    int res = 0;
    for (auto x: mp[name]){
        res = max(res, 1 + generation(x));
    }
    return res;
}

int main(){

    string x1, x2;

    while(1){
        cin >> x1;
        if (x1 == "***")
            break;
        cin >> x2;
        mp[x2].push_back(x1);
    }

    string command;
    while(1){
        cin >> command;
        if (command == "***")
            break;
        if (command == "descendants"){
            string x;
            cin >> x;
            int res = descendants(x);
            cout <<  res << endl;
        }else if (command == "generation"){
            string x;
            cin >> x;
            int res = generation(x);
            cout << res << endl;
        }
    }
}
