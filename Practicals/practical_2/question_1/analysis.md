# Problem 1: Dinner Table Arrangements - Analysis

## Algorithm: Bitmask DP + Hamiltonian Path

### Approach

This is a variant of the Hamiltonian Path problem where we need to arrange N friends around a table such that no two adjacent persons share any common allergy.

**Key Insights:**

1. Represent each person's allergies as a bitmask (bit i is set if person has allergy i)
2. Two persons can sit adjacent only if their allergy bitmasks have no common bits (bitwise AND = 0)
3. Use DP with bitmask to check if a valid arrangement exists

### Solution Structure

1. Read allergies and convert to bitmasks
2. Precompute conflict matrix: `conflict[i][j] = true` if persons i and j share an allergy
3. DP state: `dp[mask][i]` = true if we can arrange persons in the bitmask with person i as the last person
4. Transition: From state (mask, i), try to add person j if:
   - j is not in mask
   - j and i don't conflict
5. Check if we can reach state ((1<<n)-1, any person)

### Complexity

- **Time:** O(2^N \* N^2) per test case
- **Space:** O(2^N \* N)
- Suitable for N ≤ 20

### Example Walkthrough

**Test Case 1:**

- Person 0: allergies {1, 2} → mask = 0b011
- Person 1: allergies {2, 3} → mask = 0b110
- Person 2: allergies {3} → mask = 0b100

Conflicts: 0-1 (share bit 1), 1-2 (share bit 2), 0-2 (no conflict)
Valid arrangement: 0 → 2 → 1 → Answer: YES

**Test Case 2:**

- Person 0: allergies {1, 2} → mask = 0b001
- Person 1: allergies {2} → mask = 0b010
- Person 2: allergies {3} → mask = 0b100
- Person 3: allergies {4} → mask = 0b1000

All pairs have conflicts or create impossible cycles → Answer: NO
