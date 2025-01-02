#include<bits/stdc++.h>

using namespace std;

int Q = 1000000007;

int mem[1000][1000] = {0};

int C(int k, int n){
    if (mem[k][n])
        return mem[k][n];

    if (k >= n) return 1;
    if (k == 1) return n;
    mem[k][n] = (C(k-1, n-1) + C(k, n-1)) %Q;
    return mem[k][n];
}

int main(){
    int k, n;
    cin >> k >> n;
    cout << (C(k, n));
}
