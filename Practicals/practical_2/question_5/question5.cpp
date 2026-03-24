#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    // Dijkstra's algorithm for finding shortest path from node 1 to node n
    vector<vector<pair<int, long long>>> graph(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        
        // Bidirectional edge
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    
    // Dijkstra's algorithm
    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    
    dist[1] = 0;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    if (dist[n] == INF) {
        cout << "-1\n";
    } else {
        cout << dist[n] << "\n";
    }
    
    return 0;
}
