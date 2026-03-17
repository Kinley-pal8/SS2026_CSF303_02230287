# Problem 3: Remove Duplicates

## Problem Summary

Given N integers (possibly with duplicates), remove all duplicates and print the unique values in sorted order.

## Algorithm Explanation

1. Read N integers into a vector
2. Sort the vector using `sort()` - O(n log n)
3. Use `unique()` algorithm to remove consecutive duplicates and return new end iterator - O(n)
4. Erase elements from the new end to actual end using `erase()` - O(k) where k is number of duplicates
5. Print the vector containing only unique elements

The algorithm relies on the fact that `unique()` removes consecutive duplicates, which is why sorting first is essential.

## Time Complexity Analysis

- **Reading input:** O(n)
- **Sorting:** O(n log n) - dominant operation
- **Unique operation:** O(n) - single pass
- **Erase operation:** O(k) where k is number of duplicate elements
- **Printing:** O(m) where m is number of unique elements (m ≤ n)
- **Overall Time Complexity:** O(n log n)

Sorting dominates the total time complexity.

## Space Complexity Analysis

- **Vector storage:** O(n) - initially stores all N integers
- **After unique:** O(m) where m is number of unique elements
- **Other variables:** O(1) - loop counters and iterators
- **Overall Space Complexity:** O(n)

## Reflection

This problem taught me how the `unique()` STL function works and its dependency on sorted data. Key learnings:

- `unique()` only removes consecutive duplicates, so sorting is prerequisite
- The function returns an iterator to the new end of the range
- `erase()` needs to be called to physically remove the duplicate references
- For unsorted data with many duplicates, this approach (O(n log n)) is better than using a set (O(n log n))
- This technique is memory-efficient in-place removal compared to creating new containers
