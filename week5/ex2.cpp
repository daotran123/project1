#include<bits/stdc++.h>

using namespace std;

vector<int> edges[100001];
int n, m;
int visited[10001] = {0};
vector<int > res;

void BFS(int k){
    queue<int> q;
    q.push(k);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (auto x : edges[u]){
            if (!visited[x]){
                visited[x] = 1;
                q.push(x);
            }
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

    for (int i = 1; i<= n; i++){
        sort(edges[i].begin(), edges[i].end());
    }
    for (int i = 1; i<= n; i++){
        if (!visited[i]){
            visited[i] = 1;
            BFS(i);
        }
    }
}
