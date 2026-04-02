#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;

const int INF = 1e9; // Representing infinity

/**
 * Floyd Warshall Algorithm
 * 
 * Computes shortest paths between all pairs of vertices in a weighted graph.
 * Works with both positive and negative edge weights (but no negative cycles).
 * 
 * Time Complexity: O(V^3)
 * Space Complexity: O(V^2)
 */
class FloydWarshall {
private:
    int V; // Number of vertices
    vector<vector<int>> dist; // Distance matrix
    
public:
    FloydWarshall(int vertices) : V(vertices) {
        // Initialize distance matrix
        dist.assign(V, vector<int>(V, INF));
        
        // Distance from vertex to itself is 0
        for (int i = 0; i < V; i++) {
            dist[i][i] = 0;
        }
    }
    
    // Add an edge to the graph
    void addEdge(int u, int v, int weight) {
        dist[u][v] = min(dist[u][v], weight); // Handle multiple edges
    }
    
    // Floyd Warshall Algorithm
    void floydWarshall() {
        // k is the intermediate vertex
        for (int k = 0; k < V; k++) {
            // For each pair of vertices (i, j)
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    // If path through k is shorter, update distance
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
    
    // Print the distance matrix
    void printMatrix() {
        cout << "\nDistance Matrix:\n";
        cout << "    ";
        for (int i = 0; i < V; i++) {
            cout << setw(6) << i;
        }
        cout << "\n";
        
        for (int i = 0; i < V; i++) {
            cout << setw(3) << i << " ";
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INF) {
                    cout << setw(6) << "INF";
                } else {
                    cout << setw(6) << dist[i][j];
                }
            }
            cout << "\n";
        }
    }
    
    // Get shortest distance between two vertices
    int getDistance(int u, int v) {
        if (dist[u][v] == INF) return -1;
        return dist[u][v];
    }
    
    // Check for negative cycles
    bool hasNegativeCycle() {
        for (int i = 0; i < V; i++) {
            if (dist[i][i] < 0) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    cout << "===== Floyd Warshall Algorithm =====\n";
    cout << "Finds shortest paths between all pairs of vertices\n\n";
    
    // Create a graph with 4 vertices
    FloydWarshall fw(4);
    
    // Add edges (u, v, weight)
    fw.addEdge(0, 1, 5);
    fw.addEdge(0, 3, 10);
    fw.addEdge(1, 2, 3);
    fw.addEdge(2, 3, 1);
    fw.addEdge(3, 0, 2);
    fw.addEdge(3, 2, 9);
    
    cout << "Graph edges added:\n";
    cout << "0 -> 1 (weight: 5)\n";
    cout << "0 -> 3 (weight: 10)\n";
    cout << "1 -> 2 (weight: 3)\n";
    cout << "2 -> 3 (weight: 1)\n";
    cout << "3 -> 0 (weight: 2)\n";
    cout << "3 -> 2 (weight: 9)\n";
    
    // Run Floyd Warshall algorithm
    fw.floydWarshall();
    
    // Print results
    fw.printMatrix();
    
    // Check for negative cycles
    if (fw.hasNegativeCycle()) {
        cout << "\n⚠ Warning: Graph contains negative cycle!\n";
    } else {
        cout << "\n✓ No negative cycles detected.\n";
    }
    
    // Query some distances
    cout << "\nSample queries:\n";
    cout << "Distance from 0 to 3: " << fw.getDistance(0, 3) << "\n";
    cout << "Distance from 1 to 3: " << fw.getDistance(1, 3) << "\n";
    cout << "Distance from 2 to 0: " << fw.getDistance(2, 0) << "\n";
    
    return 0;
}
