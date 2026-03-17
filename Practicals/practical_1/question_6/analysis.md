# Problem 6: K Largest Elements

## Problem Summary

Given N numbers and an integer K, find and print the K largest numbers from the array in descending order.

## Algorithm Explanation

1. Read N integers and K from user input
2. Insert all N elements into a **max heap (priority_queue)**
3. Extract and print the top K elements from the heap:
   - Each `top()` operation returns the largest remaining element
   - `pop()` removes it from the heap
   - Repeat K times

The max heap automatically organizes elements such that the largest is always at the top.

## Time Complexity Analysis

- **Reading input:** O(n)
- **Inserting into max heap:** O(n log n) - each insertion is O(log n)
- **Extracting K largest:** O(k log n) - each extraction (top + pop) is O(log n)
- **Overall Time Complexity:** O(n log n)

The heap insertion dominates the total complexity.

## Space Complexity Analysis

- **Vector storage:** O(n) - stores all N integers
- **Max heap storage:** O(n) - stores all N elements
- **Other variables:** O(1) - k, counters
- **Overall Space Complexity:** O(n)

## Reflection

This problem showcased the power of priority queues for selection problems. Key learnings:

- Priority queues are perfect when we need sorted access without fully sorting
- A max heap ensures the largest element is always accessible in O(1)
- This approach is more efficient than sorting entire array (which would give O(n log n) and still require K extractions)
- For very large K close to n, this is much better than using a min heap of size K (which would be O(n log k))
- The priority_queue automatically maintains heap property after each insertion
