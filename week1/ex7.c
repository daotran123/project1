#include<bits/stdc++.h>

using namespace std;
int main()
{
    string p1, p2, t;
    getline(cin, p1);
    getline(cin, p2);
    getline(cin, t);
    while (t.find(p1) != npos){
        index = t.find(p1);
        t.erase(index, p1.length());
        t.insert(index, p2);
    }
    cout << t;
}
