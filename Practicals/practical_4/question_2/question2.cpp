#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <iomanip>

using namespace std;

const long long INF = 1e18; // Representing infinity

/**
 * Johnson's Algorithm
 * 
 * Solves the all-pairs shortest path problem for sparse graphs.
 * Uses Bellman-Ford for preprocessing and Dijkstra for each vertex.
 * Handles negative weights but not negative cycles.
 * 
 * Time Complexity: O(V*E*log(V)) - Better for sparse graphs
 * Space Complexity: O(V²)
 */
class Edge {
public:
    int u, v;
    long long weight;
    
    Edge(int _u, int _v, long long _w) : u(_u), v(_v), weight(_w) {}
};

class JohnsonsAlgorithm {
private:
    int V, E;
    vector<Edge> edges;
    vector<vector<pair<int, long long>>> adj; // Adjacency list with weights
    vector<long long> h; // Potential function values
    
public:
    JohnsonsAlgorithm(int vertices, int edgeCount) 
        : V(vertices), E(edgeCount), adj(vertices), h(vertices, 0) {}
    
    // Add an edge to the graph
    void addEdge(int u, int v, long long weight) {
        edges.push_back(Edge(u, v, weight));
        adj[u].push_back({v, weight});
    }
    
    // Bellman-Ford algorithm for computing potential values
    bool bellmanFord() {
        // Create temporary vector to store distances from source
        vector<long long> dist(V, INF);
        dist[0] = 0;
        
        // Relax edges V-1 times
        for (int i = 0; i < V - 1; i++) {
            for (const Edge& e : edges) {
                if (dist[e.u] != INF && dist[e.u] + e.weight < dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.weight;
                }
            }
        }
        
        // Check for negative cycles
        for (const Edge& e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.weight < dist[e.v]) {
                cout << "Error: Graph contains negative cycle!\n";
                return false;
            }
        }
        
        // Set potential values
        for (int i = 0; i < V; i++) {
            h[i] = dist[i];
        }
        
        return true;
    }
    
    // Dijkstra's algorithm with modified weights
    vector<long long> dijkstra(int source) {
        vector<long long> dist(V, INF);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        dist[source] = 0;
        pq.push({0, source});
        
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            if (d > dist[u]) continue;
            
            for (auto [v, w] : adj[u]) {
                // Use reweighted edge: w' = w + h[u] - h[v]
                long long reweighted = w + h[u] - h[v];
                
                if (dist[u] + reweighted < dist[v]) {
                    dist[v] = dist[u] + reweighted;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist;
    }
    
    // Run Johnson's algorithm
    vector<vector<long long>> johnsonsAlgorithm() {
        cout << "Step 1: Running Bellman-Ford for potential values...\n";
        if (!bellmanFord()) {
            return vector<vector<long long>>();
        }
        cout << "✓ Potential values computed\n";
        
        cout << "\nStep 2: Running Dijkstra from each vertex...\n";
        vector<vector<long long>> dist(V, vector<long long>(V, INF));
        
        // Run Dijkstra from each vertex
        for (int i = 0; i < V; i++) {
            vector<long long> dijkDist = dijkstra(i);
            for (int j = 0; j < V; j++) {
                if (dijkDist[j] != INF) {
                    // Convert back: dist[i][j] = dijkDist[j] - h[i] + h[j]
                    dist[i][j] = dijkDist[j] - h[i] + h[j];
                }
            }
        }
        cout << "✓ All-pairs shortest paths computed\n";
        
        return dist;
    }
    
    // Print the distance matrix
    void printMatrix(const vector<vector<long long>>& dist) {
        cout << "\nAll-Pairs Shortest Paths:\n";
        cout << "    ";
        for (int i = 0; i < V; i++) {
            cout << setw(8) << i;
        }
        cout << "\n";
        
        for (int i = 0; i < V; i++) {
            cout << setw(3) << i << " ";
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INF) {
                    cout << setw(8) << "INF";
                } else {
                    cout << setw(8) << dist[i][j];
                }
            }
            cout << "\n";
        }
    }
};

int main() {
    cout << "===== Johnson's Algorithm =====\n";
    cout << "All-pairs shortest paths for sparse graphs\n\n";
    
    JohnsonsAlgorithm ja(5, 8);
    
    // Add edges (source, destination, weight)
    ja.addEdge(0, 1, 3);
    ja.addEdge(0, 2, 8);
    ja.addEdge(0, 4, -4);
    ja.addEdge(1, 3, 1);
    ja.addEdge(1, 4, 7);
    ja.addEdge(2, 1, 4);
    ja.addEdge(3, 0, 2);
    ja.addEdge(3, 2, -5);
    
    cout << "Graph with 5 vertices and 8 edges\n";
    cout << "Edges added (including negative weights)\n\n";
    
    // Run Johnson's algorithm
    vector<vector<long long>> dist = ja.johnsonsAlgorithm();
    
    if (!dist.empty()) {
        ja.printMatrix(dist);
        
        cout << "\nSample shortest paths:\n";
        cout << "0 to 2: " << (dist[0][2] == INF ? -1 : dist[0][2]) << "\n";
        cout << "0 to 3: " << (dist[0][3] == INF ? -1 : dist[0][3]) << "\n";
        cout << "1 to 0: " << (dist[1][0] == INF ? -1 : dist[1][0]) << "\n";
    }
    
    return 0;
}
