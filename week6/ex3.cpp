#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m, s, t;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next] > 0) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

int maxflow() {
    int flow = 0;
    vector<int> parent(n + 1);
    int new_flow;

    while ((new_flow = bfs(parent))) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

int main() {
    cin >> n >> m;
    cin >> s >> t;

    capacity.assign(n + 1, vector<int>(n + 1, 0));
    adj.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, cap;
        cin >> u >> v >> cap;
        capacity[u][v] += cap;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << maxflow() << endl;
    return 0;
}

