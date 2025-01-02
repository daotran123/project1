#include <bits/stdc++.h>
using namespace std;

int parent[100001];
int rank_[100001];
int n, m;

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

vector<Edge> edges;

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int Find(int x) {
    if (parent[x] == -1) {
        return x;
    }
    return parent[x] = Find(parent[x]);
}

void Union(int u, int v) {
    int root_u = Find(u);
    int root_v = Find(v);

    if (root_u != root_v) {
        if (rank_[root_u] < rank_[root_v]) {
            parent[root_u] = root_v;
        } else if (rank_[root_u] > rank_[root_v]) {
            parent[root_v] = root_u;
        } else {
            parent[root_v] = root_u;
            rank_[root_u]++;
        }
    }
}

void Kruskal() {
    fill(parent, parent + n + 1, -1);
    fill(rank_, rank_ + n + 1, 0);

    sort(edges.begin(), edges.end(), cmp);

    int edge_count = 0;
    int mst_weight = 0;

    for (const auto& edge : edges) {
        if (edge_count == n - 1) break;

        int u = edge.u;
        int v = edge.v;
        int w = edge.w;

        int root_u = Find(u);
        int root_v = Find(v);

        if (root_u != root_v) {
            Union(u, v);
            mst_weight += w;
            edge_count++;
        }
    }

    if (edge_count == n - 1) {
        cout << mst_weight << endl;
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    Kruskal();
    return 0;
}
