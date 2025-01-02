#include<bits/stdc++.h>

using namespace std;

int a[25];

int Try(int k){
    if (a[k] || k == 0){
        return a[k];
    }
    a[k] = Try(k-1) + Try(k-2);
    return a[k];
}

int main(){
    a[0] = 0;
    a[1] = 1;
    int n;
    cin >> n;
    a[n-1] = Try(n-1);
    cout << a[n-1];
}
