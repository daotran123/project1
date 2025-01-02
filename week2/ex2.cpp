#include<bits/stdc++.h>

using namespace std;

int n;
int res[10000];
int visited[10000] = {0};

void Try(int k){
    if (k == n){
        for (int i = 0; i< n; i++){
            cout << res[i] << " ";

        }
        cout << endl;
        return;
    }
    for (int i = 1; i<= n; i++){
        if (!visited[i]){
            visited[i] = 1;
            res[k] = i;
            Try(k+1);
            visited[i] = 0;
        }
    }
}

int main(){
    cin >> n;
    Try(0);
}
