#include<bits/stdc++.h>

using namespace std;

vector<int> edges[100001];
int n, m;
int visited[10001] = {0};
vector<int > res;

void DFS(int k){
    cout << k << " ";
    for (auto x: edges[k]){
        if (!visited[x]){
            visited[x] = 1;
            DFS(x);
        }
    }
}

bool cmp(int a, int b){
    return a> b;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i< m; i++){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    visited[1] = 1;
    DFS(1);
}
