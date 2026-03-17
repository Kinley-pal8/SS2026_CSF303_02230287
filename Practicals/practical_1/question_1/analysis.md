# Problem 1: Dynamic Array Basics

## Problem Summary

Read N integers from user input, store them in a dynamic vector, and output the maximum element, minimum element, and sum of all elements.

## Algorithm Explanation

1. Use a `vector<int>` to dynamically store N integers
2. Read N from user input
3. Use `max_element()` to find the maximum value in O(n) time
4. Use `min_element()` to find the minimum value in O(n) time
5. Iterate through the vector once to calculate the sum in O(n) time
6. Display all three results

The algorithm leverages STL functions for clean and efficient implementation.

## Time Complexity Analysis

- **Reading input:** O(n)
- **Finding max element:** O(n) - requires scanning entire array
- **Finding min element:** O(n) - requires scanning entire array
- **Calculating sum:** O(n) - requires iterating through all elements
- **Overall Time Complexity:** O(n)

Since all operations are performed sequentially and each is O(n), the total complexity is **O(n)**.

## Space Complexity Analysis

- **Vector storage:** O(n) - stores all N integers
- **Other variables:** O(1) - maxElement, minElement, sum use constant space
- **Overall Space Complexity:** O(n)

## Reflection

This problem reinforced the importance of using STL containers (vectors) over traditional arrays for dynamic sizing. Key learnings:

- Vectors automatically manage memory allocation and deallocation
- STL algorithms like `max_element()` and `min_element()` are optimized and reduce code complexity
- Using `long long` for sum prevents integer overflow with large inputs
- Time complexity remains O(n) regardless of using STL functions vs manual loops
