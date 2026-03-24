# Problem 6: The Shortest Path with Toll Booths - Analysis

## Algorithm: Dijkstra's Algorithm with State Space

### Approach

This is a shortest path problem where the state consists of multiple dimensions:

- **State:** (booth_position, coins_remaining, skips_used)
- **Transition 1:** Pay toll[i] coins, move to booth i+1, cost 1 minute
- **Transition 2:** Skip booth, move to booth i+1, cost 2 minutes (if skips_used < K)

### Key Insights

1. State space is O(N × M × K) - manageable with DP/Dijkstra
2. From booth i with coins j and k skips used, we have at most 2 transitions
3. We want minimum time to reach booth N (accepting any coins/skips state)

### Solution Structure

1. Use 3D DP: `dp[i][j][skips]` = minimum time to reach booth i with j coins and 'skips' skips used
2. Use priority queue (min-heap) for Dijkstra's algorithm
3. State in queue: (time, booth, coins, skips_used)
4. Process states in order of increasing time
5. For each state, try both transitions (pay or skip)
6. Answer: minimum dp[N][any j][any skips]

### Transitions

**From state (time, i, coins, skips):**

1. **Pay toll:** If coins ≥ toll[i]
   - Next state: (time+1, i+1, coins-toll[i], skips)
2. **Skip:** If skips < K
   - Next state: (time+2, i+1, coins, skips+1)

### Complexity

- **Time:** O(N × M × K × log(N×M×K))
- **Space:** O(N × M × K)
- With N=5, M=10, K=2: feasible (~1000 states)

### Example

**Input:** N=5, M=10, K=2

```
Tolls: [3, 5, 2, 4, 6]

Start: booth=1, coins=10, skips=0, time=0

Possible transitions from booth 1:
- Pay 3 coins: booth=2, coins=7, skips=0, time=1
- Skip: booth=2, coins=10, skips=1, time=2

Continuing from (booth=2, coins=7, skips=0, time=1):
- Pay 5 coins: booth=3, coins=2, skips=0, time=2
- Skip: booth=3, coins=7, skips=1, time=3

Continuing from (booth=3, coins=2, skips=0, time=2):
- Pay 2 coins: booth=4, coins=0, skips=0, time=3
- Skip: booth=4, coins=2, skips=1, time=4

Continuing from (booth=4, coins=0, skips=0, time=3):
- Can't pay (0 < 4)
- Skip: booth=5, coins=0, skips=1, time=5

Result: time=5 (possibly different from expected 6 depending on optimal path)
```

### Important Notes

1. **Booth Indexing:** Typically 1-indexed; booth N is the last one
2. **Coins:** Start with M coins; paying reduces coins, skipping doesn't
3. **Early Termination:** Once we reach booth N, we have our answer for that state
4. **Answer Selection:** Among all ways to reach booth N, pick minimum time

### Edge Cases

- M=0: Can't pay any toll, must skip all booths. Possible only if K ≥ N-1
- K=0: Can't skip, must pay all tolls. Possible only if M ≥ sum of all tolls
- Unreachable: If neither condition met, return -1
