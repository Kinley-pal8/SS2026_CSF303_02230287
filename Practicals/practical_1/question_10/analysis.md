# Problem 10: Count of Subsets with Sum Equal to Target

## Problem Summary

Given an array of N integers and a target sum, count the number of subsets whose elements sum to exactly the target value.

## Algorithm Explanation

1. Read N elements and target sum from user input
2. Calculate total subsets = 2^N (using bit shift: `1 << n`)
3. For each mask from 0 to 2^N - 1:
   - Initialize sum = 0
   - For each bit position i from 0 to n-1:
     - If i-th bit is set in mask: add arr[i] to sum
   - Check if sum equals target: `sum == target`
   - If equal, increment the counter
4. Print the total count of subsets with sum equal to target

The algorithm generates all possible subsets and filters those matching the target sum.

## Time Complexity Analysis

- **Reading input:** O(1) (constant number of reads)
- **Generating and checking all subsets:** O(n × 2^n)
  - 2^n subsets to generate
  - For each subset, we sum n elements: O(n)
- **Comparison:** O(1) per subset
- **Overall Time Complexity:** O(n × 2^n)

## Space Complexity Analysis

- **Vector storage:** O(n) - stores all N integers
- **Counter and sum variables:** O(1)
- **Overall Space Complexity:** O(n)

## Reflection

This problem is the culmination of understanding bitmask techniques for subset enumeration with constraints. Key learnings:

- The bitmask approach systematically explores all 2^n subsets
- The constraint (sum == target) is checked for each subset
- For small n (typically n ≤ 20), this bitmask approach is practical and efficient
- Alternative dynamic programming approach (0/1 Knapsack) would be O(n × target) time
  - Bitmask is better when target is very large or n is small
  - DP is better when target is small and n is large
- This problem bridges subset generation with practical constraint satisfaction
- The elegance of bitmask techniques makes complex combinatorial problems tractable
