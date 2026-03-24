# Problem 3: Sliding Window Maximum - Analysis

## Algorithm: Deque-Based Approach

### Approach

Use a deque (double-ended queue) to efficiently track the maximum element in each sliding window:

1. **Deque Invariant:** Store indices in deque in decreasing order of their element values
2. **Remove from front:** Remove indices that are outside the current window
3. **Remove from back:** Remove indices whose values are ≤ current element (they can never be maximum)
4. **Add current element:** Push current index to deque
5. **Query:** The front of deque always has the maximum element index

### Why Deque Works

- Deque maintains elements in decreasing order
- Front element is always the maximum
- Each element is added once and removed at most once
- Total operations are O(N), not O(N\*K) like naive approach

### Solution Structure

1. Process first K elements: Remove smaller elements from back, add to deque
2. Output the maximum (front of deque)
3. For each remaining element (i from K to N-1):
   - Remove indices outside window from front
   - Remove smaller elements from back
   - Add current index
   - Output maximum (front of deque)

### Complexity

- **Time:** O(N) - each element processed exactly once for add and remove
- **Space:** O(K) for the deque storage

### Example

**Input:** arr = [1, 3, -1, -3, 5, 3, 6, 7], K = 3

Windows and deque states:

```
Window [1, 3, -1]: deque = [1(3)] → output 3
Window [3, -1, -3]: deque = [1(3)] → output 3
Window [-1, -3, 5]: deque = [4(5)] → output 5
Window [-3, 5, 3]: deque = [4(5)] → output 5
Window [5, 3, 6]: deque = [6(6)] → output 6
Window [3, 6, 7]: deque = [7(7)] → output 7
```

**Output:** 3 3 5 5 6 7 ✓
