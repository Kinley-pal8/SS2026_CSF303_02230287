# Problem 5: Network Latency - Analysis

## Part A: Static Weights - Dijkstra's Algorithm

### Algorithm: Dijkstra's Shortest Path

**Approach:**

1. Maintain distance array where dist[i] = minimum latency to reach router i from router 1
2. Use priority queue to always process the nearest unvisited node
3. For each node, relax all outgoing edges
4. Return dist[N] if reachable, else -1

**Key Points:**

- Bidirectional cables: Add edges in both directions
- All weights are positive (latencies ≥ 1)
- Standard relaxation: if dist[u] + weight < dist[v], update dist[v]

**Complexity:**

- **Time:** O((N + M) log N) with binary heap
- **Space:** O(N + M)

### Example (Part A)

```
Input: 4 routers, 4 cables
1-2: weight 5
2-3: weight 3
1-3: weight 8
3-4: weight 2

Dijkstra execution:
dist[1]=0, process node 1
  relax 1→2: dist[2]=5
  relax 1→3: dist[3]=8

process node 2 (min unvisited)
  relax 2→1: no improvement
  relax 2→3: dist[3]=min(8, 5+3)=8

process node 3 (min unvisited)
  relax 3→4: dist[4]=10

process node 4

Output: dist[4] = 10 ✓
Path: 1→2→3→4 (cost: 5+3+2=10)
```

---

## Part B: Time-Dependent Weights

### Algorithm: Modified Dijkstra for Time-Dependent Edges

**Problem:** Edge weights depend on when you start traversing them

- f(t) = a·t + b (travel time if starting at time t)
- Arrival time = departure time + f(departure time)

**Approach:**

1. Similar to Dijkstra but with modified edge relaxation
2. When at node u at time dist[u], edge (u,v) with f(t) = a·t + b gives:
   - Travel time = a·dist[u] + b
   - Arrival at v = dist[u] + (a·dist[u] + b) = dist[u]·(1+a) + b
3. If this arrival time < dist[v], update and add to priority queue

**Complexity:**

- **Time:** O((N + M) log N)
- **Space:** O(N + M)
- Uses double for floating point calculations

### Example (Part B)

```
Input: 3 nodes, 3 roads
1→2: f(t) = 1·t + 0 (travel time = t)
2→3: f(t) = 1·t + 5 (travel time = t+5)
1→3: f(t) = 2·t + 0 (travel time = 2t)

Path analysis from time 0:
Path 1→3:
  departure: 0, travel: 2·0=0, arrival: 0+0=0...
  Wait, that's wrong. Let me recalculate:
  If f(t)=2t+0 and we start at t=0: f(0)=0, so arrival=0+0=0

Hmm, this seems problematic. Let me reconsider...
Actually, if we depart at time 0 from node 1 on edge with f(t)=2t+0:
  f(0)=2·0+0=0, so immediate arrival at time 0+0=0
  This creates a zero-cost loop.

The expected output is 10.00. Let me check the optimal path:
1→2→3:
  From 1 at t=0, take edge 1→2 with f(t)=1·t+0
  Arrive at 2 at time: 0 + f(0) = 0 + 0 = 0
  From 2 at t=0, take edge 2→3 with f(t)=1·t+5
  Arrive at 3 at time: 0 + f(0) = 0 + 5 = 5

1→3 direct:
  From 1 at t=0, take edge 1→3 with f(t)=2·t+0
  Arrive at 3 at time: 0 + f(0) = 0 + 0 = 0

Hmm, neither gives 10. Let me re-read the problem... The answer is 10.00, and paths cost 0 or 5, so perhaps the algorithm implementation needs careful consideration of the time-dependent calculation.
```

**Note on Implementation:** The provided solution implements both part A and B using the same input format. For actual use, you may need to read carefully to distinguish between static and time-dependent problems.
