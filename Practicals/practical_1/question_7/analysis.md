# Problem 7: Finding Medians in a Running Stream

## Problem Summary

For a stream of N integers, after adding each integer, find and print the median of all integers processed so far. The median is formatted to 1 decimal place.

## Algorithm Explanation

1. Use **two heaps** to efficiently maintain the median:
   - **Max heap:** Stores the smaller half of all numbers seen so far
   - **Min heap:** Stores the larger half of all numbers seen so far
2. For each new integer:
   - Add to appropriate heap: compare with max heap top
   - Balance heaps so: |maxHeap.size() - minHeap.size()| ≤ 1
   - Calculate median:
     - Odd total count: median = max heap top
     - Even total count: median = (max heap top + min heap top) / 2.0
3. Print median formatted to 1 decimal place

This approach maintains a "floating" median that updates efficiently with each new element.

## Time Complexity Analysis

- **Per element insertion:** O(log n) - inserting into heap and rebalancing
- **Per median calculation:** O(1) - just accessing heap tops
- **For n elements:** O(n log n)
- **Overall Time Complexity:** O(n log n)

## Space Complexity Analysis

- **Two heaps storage:** O(n) - collectively store all n elements
- **Other variables:** O(1)
- **Overall Space Complexity:** O(n)

## Reflection

This problem was enlightening in understanding the two-heap technique for dynamic median finding. Key learnings:

- Naive approach of sorting after each insertion would be O(n² log n) - extremely inefficient
- The two-heap approach elegantly splits the problem into two halves
- The max heap keeps the smaller half with largest element accessible at top
- The min heap keeps the larger half with smallest element accessible at top
- This technique is widely used in real-time data analysis and streaming applications
- Initially, I didn't realize heap balancing was crucial; the imbalance ensures median is always at one of the heap tops
