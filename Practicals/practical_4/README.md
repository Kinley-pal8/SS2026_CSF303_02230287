# Practical 4 - Advanced Graph Algorithms

This practical implements three fundamental graph algorithms with detailed analysis and reflections.

## Questions Overview

### Question 1: Floyd Warshall Algorithm

**What it does**: Finds shortest paths between all pairs of vertices in a weighted graph.

**File**: `question_1/question1.cpp`

**Key Features**:

- Time Complexity: O(V³)
- Handles negative weights (but not negative cycles)
- Dynamic programming approach
- Simple, elegant implementation
- Suitable for small/medium graphs (V ≤ 500)

**Sample Output**:

```
Distance from 0 to 3: 9
Distance from 1 to 3: 4
Distance from 2 to 0: 3
```

**When to use**:

- Need all-pairs shortest paths
- Graph has negative weights
- Graph is relatively dense
- Need to detect negative cycles

---

### Question 2: Johnson's Algorithm

**What it does**: Efficiently finds shortest paths between all pairs in sparse graphs using Bellman-Ford preprocessing + Dijkstra.

**File**: `question_2/question2.cpp`

**Key Features**:

- Time Complexity: O(V·E·log(V)) - Better for sparse graphs
- Combines Bellman-Ford (preprocessing) with Dijkstra (main computation)
- Uses potential function for edge reweighting
- Handles negative weights efficiently
- More efficient than Floyd Warshall for sparse graphs

**Algorithm Steps**:

1. Run Bellman-Ford to compute potential values
2. Reweight all edges using potential function
3. Run Dijkstra from each vertex
4. Convert distances back to original weights

**When to use**:

- Sparse graphs with E << V²
- Negative weights present
- Memory constrained (large V)
- Need practical efficiency over theoretical elegance

---

### Question 3: Baruvka's Algorithm

**What it does**: Finds the Minimum Spanning Tree (MST) of a weighted undirected graph.

**File**: `question_3/question3.cpp`

**Key Features**:

- Time Complexity: O(E·log(V))
- One of the oldest MST algorithms (1926)
- Greedy approach with Union-Find
- Naturally parallelizable
- Works on both dense and sparse graphs
- Outputs: V-1 edges with minimum total weight

**MST Properties**:

- Connects all vertices with minimum total edge weight
- Contains exactly V-1 edges for V vertices
- No cycles (tree structure)
- Total weight is optimal (provably)

**Sample MST Output**:

```
Edge 1: (1, 2) weight: 1
Edge 2: (0, 2) weight: 2
Edge 3: (3, 4) weight: 2
Edge 4: (4, 5) weight: 3
Edge 5: (1, 3) weight: 5
Total weight: 13
```

**When to use**:

- Need minimum spanning tree
- Undirected weighted graph
- Parallel processing available
- Understanding MST fundamentals

---

## Compilation and Execution

### Question 1 - Floyd Warshall

```bash
cd question_1
g++ -o Q1 question1.cpp
./Q1
```

### Question 2 - Johnson's Algorithm

```bash
cd question_2
g++ -std=c++17 -o Q2 question2.cpp
./Q2
```

### Question 3 - Baruvka's Algorithm

```bash
cd question_3
g++ -o Q3 question3.cpp
./Q3
```

---

## Detailed Analysis

Each question directory contains:

- **question[n].cpp**: Full implementation with detailed comments
- **analysis.md**: Comprehensive analysis including:
  - Algorithm overview
  - How it works step-by-step
  - Time and space complexity
  - Advantages and disadvantages
  - When to use the algorithm
  - Real-world applications
  - Personal reflection on algorithm design and utility

---

## Algorithm Comparison

| Aspect                | Floyd Warshall          | Johnson                 | Baruvka               |
| --------------------- | ----------------------- | ----------------------- | --------------------- |
| **Problem**           | All-pairs shortest path | All-pairs shortest path | Minimum spanning tree |
| **Time**              | O(V³)                   | O(VE·log V)             | O(E·log V)            |
| **Space**             | O(V²)                   | O(V+E)                  | O(V+E)                |
| **Best For**          | Dense graphs            | Sparse graphs           | General MST           |
| **Handles Negatives** | Yes                     | Yes                     | N/A                   |
| **Difficulty**        | Easy                    | Medium                  | Medium                |

---

## Learning Objectives

After completing this practical, you should understand:

1. **Floyd Warshall**:
   - Dynamic programming for graph problems
   - All-pairs shortest path computation
   - Negative weight handling

2. **Johnson's Algorithm**:
   - Algorithm composition (combining Bellman-Ford + Dijkstra)
   - Potential function concept for edge reweighting
   - Trade-offs between different approaches
   - When simpler algorithms are more efficient

3. **Baruvka's Algorithm**:
   - Greedy algorithms for optimization
   - Minimum spanning tree properties
   - Union-Find data structure utility
   - Parallel algorithm design concepts

---

## Key Insights

1. **No single best algorithm**: Choice depends on graph characteristics (dense/sparse, weights, etc.)
2. **Composition wins**: Johnson's combines simpler algorithms better than a single approach
3. **Historical importance**: Baruvka (1926) predates modern algorithms yet remains relevant
4. **Parallelization**: Some algorithms (like Baruvka) naturally parallelize better than others
5. **Trade-offs**: Time vs space, implementation complexity vs runtime efficiency

---

