# Problem 4: Sliding Window Maximum

## Problem Summary

Given an array of size N and window size K, find and print the maximum element in every contiguous window of size K as it slides through the array.

## Algorithm Explanation

1. Use a **deque** to store indices (not values) of potentially useful elements
2. For each element at position i:
   - Remove indices from front that are outside the current window (index < i - k + 1)
   - Remove indices from back while their corresponding array values are ≤ current element
   - Add current index to the back of deque
   - When i ≥ k-1, the front of deque contains the index of maximum in current window
3. Print the maximum element from the deque front

The deque maintains only indices of elements that could be maximum in future windows.

## Time Complexity Analysis

- **Reading input:** O(n)
- **Sliding window processing:** O(n) - each element is added once and removed once from deque
- **Printing:** O(n - k + 1)
- **Overall Time Complexity:** O(n)

This is optimal because we must visit each element at least once.

## Space Complexity Analysis

- **Vector storage:** O(n) - stores all N integers
- **Deque storage:** O(k) - stores at most k indices at any time
- **Overall Space Complexity:** O(n)

## Reflection

This problem was a turning point in understanding deques and their power in sliding window problems. Key learnings:

- Initially, I investigated a brute force O(n × k) approach (finding max for each window separately)
- Using deque reduced complexity to O(n) by maintaining only useful indices
- Storing indices instead of values is crucial for tracking which element is in which window
- This technique is more efficient than using a multiset (which would be O(n log k))
- The deque cleverly maintains a monotonic decreasing order of values, enabling O(1) maximum lookup
