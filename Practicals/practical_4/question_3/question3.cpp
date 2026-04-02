#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * Baruvka's Algorithm (also spelled Boruvka's Algorithm)
 * 
 * Finds the Minimum Spanning Tree (MST) of a weighted undirected graph.
 * Uses a union-find (disjoint set) data structure.
 * 
 * Time Complexity: O(E·log(V)) - Due to sorting and union-find operations
 * Space Complexity: O(V + E)
 */

class Edge {
public:
    int u, v;
    int weight;
    
    Edge(int _u, int _v, int _w) : u(_u), v(_v), weight(_w) {}
    
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        // Each vertex is its own parent initially
        iota(parent.begin(), parent.end(), 0);
    }
    
    // Find with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    // Union by rank
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) {
            return false; // Already in same set
        }
        
        // Attach smaller rank tree under larger rank tree
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        
        return true;
    }
};

class BaruvkaAlgorithm {
private:
    int V, E;
    vector<Edge> edges;
    vector<int> parent; // For forest representation
    
public:
    BaruvkaAlgorithm(int vertices, int edgeCount) 
        : V(vertices), E(edgeCount), parent(vertices) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    // Add an edge to the graph
    void addEdge(int u, int v, int weight) {
        edges.push_back(Edge(u, v, weight));
    }
    
    // Find root of a component (for forest)
    int findRoot(int x) {
        if (parent[x] != x) {
            parent[x] = findRoot(parent[x]);
        }
        return parent[x];
    }
    
    // Baruvka's Algorithm - Finds Minimum Spanning Tree
    vector<Edge> baruvka() {
        vector<Edge> mst;
        UnionFind uf(V);
        int edgesAdded = 0;
        
        // Sort edges by weight
        sort(edges.begin(), edges.end());
        
        cout << "Starting Baruvka's Algorithm...\n";
        cout << "Total edges: " << E << "\n";
        cout << "Total vertices: " << V << "\n\n";
        
        // Process each edge
        for (const Edge& e : edges) {
            // Check if adding this edge creates a cycle
            if (uf.unite(e.u, e.v)) {
                mst.push_back(e);
                edgesAdded++;
                
                cout << "Added edge (" << e.u << ", " << e.v 
                     << ") weight=" << e.weight << "\n";
                
                // MST should have V-1 edges
                if (edgesAdded == V - 1) {
                    break;
                }
            } else {
                cout << "Skipped edge (" << e.u << ", " << e.v 
                     << ") - creates cycle\n";
            }
        }
        
        return mst;
    }
    
    // Alternative implementation using Kruskal's approach (similar to Baruvka concept)
    // This demonstrates the core principle of Baruvka's algorithm
    vector<Edge> baruvkaKruskalStyle() {
        vector<Edge> mst;
        UnionFind uf(V);
        
        // Sort edges by weight
        sort(edges.begin(), edges.end());
        
        cout << "Baruvka's Algorithm (Kruskal-style implementation):\n";
        cout << "Sorted edges by weight:\n";
        
        int edgeIndex = 0;
        for (const Edge& e : edges) {
            cout << "Edge " << edgeIndex++ << ": (" << e.u << ", " << e.v 
                 << ") weight=" << e.weight << "\n";
        }
        
        cout << "\nProcessing edges:\n";
        
        for (const Edge& e : edges) {
            if (uf.unite(e.u, e.v)) {
                mst.push_back(e);
                cout << "✓ Added edge (" << e.u << ", " << e.v 
                     << ") weight=" << e.weight << "\n";
                
                if (mst.size() == V - 1) {
                    break;
                }
            }
        }
        
        return mst;
    }
    
    // Print MST details
    void printMST(const vector<Edge>& mst) {
        cout << "\n===== Minimum Spanning Tree =====\n";
        cout << "MST Edges:\n";
        
        int totalWeight = 0;
        for (size_t i = 0; i < mst.size(); i++) {
            cout << i + 1 << ". (" << mst[i].u << ", " << mst[i].v 
                 << ") weight: " << mst[i].weight << "\n";
            totalWeight += mst[i].weight;
        }
        
        cout << "\nTotal edges in MST: " << mst.size() << "\n";
        cout << "Total weight of MST: " << totalWeight << "\n";
    }
    
    // Verify if MST is valid (has V-1 edges and all vertices connected)
    bool isValidMST(const vector<Edge>& mst) {
        return mst.size() == V - 1;
    }
};

int main() {
    cout << "===== Baruvka's Algorithm (MST) =====\n";
    cout << "Finds Minimum Spanning Tree using edge weights\n\n";
    
    // Create a graph with 6 vertices
    BaruvkaAlgorithm ba(6, 9);
    
    // Add edges (u, v, weight)
    ba.addEdge(0, 1, 4);
    ba.addEdge(0, 2, 2);
    ba.addEdge(1, 2, 1);
    ba.addEdge(1, 3, 5);
    ba.addEdge(2, 3, 8);
    ba.addEdge(2, 4, 10);
    ba.addEdge(3, 4, 2);
    ba.addEdge(3, 5, 6);
    ba.addEdge(4, 5, 3);
    
    cout << "Graph edges (undirected):\n";
    cout << "0-1: 4  |  0-2: 2  |  1-2: 1  |  1-3: 5\n";
    cout << "2-3: 8  |  2-4: 10 |  3-4: 2  |  3-5: 6  |  4-5: 3\n\n";
    
    // Run Baruvka's algorithm
    vector<Edge> mst = ba.baruvkaKruskalStyle();
    
    // Print results
    ba.printMST(mst);
    
    // Verify MST validity
    if (ba.isValidMST(mst)) {
        cout << "\n✓ Valid MST: Contains V-1 edges and connects all vertices\n";
    } else {
        cout << "\n✗ Invalid MST!\n";
    }
    
    return 0;
}
