#include<bits/stdc++.h>

using namespace std;


int n, m;

int solution(string s){
    int res = 0;
    for (int i = 0; i< s.length(); i++){
        int tmp = (int)s[i];
        res = (res * 256 + tmp) % m;
    }

    return res;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i< n; i++){
        string x;
        cin >> x;
        cout << solution(x) << endl;
    }
}
