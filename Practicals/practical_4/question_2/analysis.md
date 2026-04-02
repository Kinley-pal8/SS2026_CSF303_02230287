# Johnson's Algorithm - Analysis & Reflection

## Algorithm Overview

Johnson's Algorithm is an efficient solution for finding shortest paths between all pairs of vertices in sparse graphs. It combines Bellman-Ford and Dijkstra algorithms to achieve better performance than Floyd Warshall for sparse graphs.

## How It Works

### Phase 1: Bellman-Ford Preprocessing

1. Add a virtual source vertex connected to all vertices with weight 0
2. Run Bellman-Ford from the virtual source
3. Compute potential function h[v] = shortest distance from virtual source to v
4. Check for negative cycles in this process

### Phase 2: Edge Reweighting

- Reweight edges: w'(u,v) = w(u,v) + h[u] - h[v]
- This ensures all reweighted edges are non-negative
- Preserves shortest path properties

### Phase 3: Dijkstra from Each Source

- Run Dijkstra from each vertex on reweighted graph
- All edges are now non-negative, so Dijkstra works efficiently
- Convert results back to original weights

## Key Characteristics

- **Time Complexity**: O(V·E·log(V)) for sparse graphs
- **Space Complexity**: O(V²) for output + O(V+E) for intermediate
- **Better than Floyd Warshall when**: E << V²
- **Works with**: Negative weights (but not negative cycles)

## Comparison with Alternatives

| Algorithm      | Time        | Space  | Best Use Case         |
| -------------- | ----------- | ------ | --------------------- |
| Floyd-Warshall | O(V³)       | O(V²)  | Dense graphs, small V |
| Johnson        | O(VE·log V) | O(V+E) | Sparse graphs         |
| Dijkstra×V     | O(V²·log V) | O(V)   | Non-negative weights  |

## Advantages

1. Superior for sparse graphs: E << V²
2. Handles negative weights efficiently
3. Detects negative cycles via Bellman-Ford
4. Practical for large but sparse graphs
5. Better space efficiency in intermediate stages

## Disadvantages

1. More complex to implement than Floyd-Warshall
2. Overhead of running Bellman-Ford + V Dijkstra calls
3. Slower for dense graphs
4. Requires careful handling of edge cases

## When to Use

- Sparse graphs with negative weights
- When memory is constrained (E << V²)
- Real-time systems needing all-pairs shortest paths
- Road networks, social graphs
- When worst-case O(V³) of Floyd-Warshall is prohibitive

## Real-World Applications

- Airline networks (sparse, weighted routes)
- Telecommunication networks
- Transportation optimization
- Game networking (sparse player connections)
- Scientific computing (sparse matrices)

## Reflection

Johnson's Algorithm elegantly solves the efficiency puzzle of all-pairs shortest paths by intelligently combining two classic algorithms. The key insight is reweighting edges using a potential function to eliminate negative weights while preserving shortest paths. This allows Dijkstra—which is highly optimized—to run efficiently V times rather than using Floyd-Warshall's cubic approach. The algorithm demonstrates good practical Computer Science by adapting existing tools (Bellman-Ford for preprocessing, Dijkstra for heavy lifting) rather than creating new solutions, and choosing the right tool for the right problem characteristics (dense vs sparse). Its greatest value lies in handling sparse, negatively-weighted real-world networks where Floyd-Warshall becomes prohibitively expensive.
