#include <bits/stdc++.h>
using namespace std;

int res = 0;

void Hamiltonian(int start, int k, int count, vector<int> edges[], int visited[], int n){
    if (count == n) {
        // Check if there is an edge from current node `k` back to `start`
        for (auto x : edges[k]) {
            if (x == start) {
                res = 1;
                return;
            }
        }
    }

    for (auto x : edges[k]) {
        if (!visited[x]) {
            visited[x] = 1;
            Hamiltonian(start, x, count + 1, edges, visited, n);
            visited[x] = 0;
            if (res == 1) return;  // Early exit if Hamiltonian cycle is found
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<int> edges[n + 1];
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        res = 0;
        for (int i = 1; i <= n; i++) {
            int visited[n + 1] = {0};
            visited[i] = 1;
            Hamiltonian(i, i, 1, edges, visited, n);
            if (res == 1) break;  // Early exit if Hamiltonian cycle is found
        }

        cout << res << endl;
    }
    return 0;
}
