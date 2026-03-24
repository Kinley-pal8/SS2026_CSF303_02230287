# Problem 2: Maximum AND Subarray - Analysis

## Algorithm: Greedy Bit-by-Bit Approach

### Approach

To find the maximum AND value across all K-length subarrays, we use a greedy strategy:

1. Try to set bits from MSB (bit 29) to LSB (bit 0)
2. For each bit position, check if there exists a K-length subarray whose AND has all required bits set
3. If yes, include this bit in the result

### Key Insight

AND operation only clears bits, never sets them. So if we can find a subarray where AND contains certain bits, those bits together form a valid AND value.

**Why Greedy Works:**

- Higher bits contribute more value
- Setting a higher bit and getting a slightly lower AND is better than a higher AND with fewer bits set
- By greedily selecting from MSB, we maximize the final value

### Solution Structure

1. For each bit position from 29 down to 0:
   - Create `testResult = current_result | (1 << bit)`
   - Check if any K-length subarray has AND value that includes all bits in testResult
   - If yes, update result to include this bit
2. Return the final result

### Complexity

- **Time:** O(N _ K _ 30) = O(N \* K) per test case
- **Space:** O(N)
- For N ≤ 10^5, this is efficient

### Example

**Input:** arr = [12, 8, 15, 10, 7], K = 3

Binary representations:

- 12 = 1100
- 8 = 1000
- 15 = 1111
- 10 = 1010
- 7 = 0111

Subarrays of length 3:

- [12, 8, 15]: 1100 & 1000 & 1111 = 1000 = 8
- [8, 15, 10]: 1000 & 1111 & 1010 = 1000 = 8
- [15, 10, 7]: 1111 & 1010 & 0111 = 0010 = 2

Maximum AND = 8 ✓
