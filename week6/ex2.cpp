#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<pair<int, int>> vt[100001];
vector<int> dis;
vector<int> visited;

void dijkstra(int start) {
    dis[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = 1;

        for (auto x : vt[u]) {
            int v = x.first;
            int weight = x.second;

            if (dis[u] + weight < dis[v]) {
                dis[v] = dis[u] + weight;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    dis.assign(n + 1, 1e9);
    visited.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vt[u].push_back({v, w});
    }
    cin >> s >> t;

    dijkstra(s);

    if (dis[t] == 1e9) {
        cout << -1;
    } else {
        cout << dis[t];
    }
}
