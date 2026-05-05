# PRACTICAL 6 - ADVANCED STRING ALGORITHMS

## Overview

Three advanced algorithms for efficient string processing:

1. **Trie** - O(m) prefix-based string storage and retrieval
2. **PATRICIA Tree** - Space-optimized Trie with edge compression
3. **Manacher's Algorithm** - O(n) longest palindromic substring finder

---

## Question 1: TRIE DATA STRUCTURE

**Files:** `question1.cpp`, `Q1` (executable), `reflection.md`

A tree where each node represents a character. Paths from root form strings.

**Operations:**
- `insert(word)` - Add a word (O(m) time)
- `search(word)` - Check if word exists (O(m) time)
- `startsWith(prefix)` - Check prefix (O(m) time)
- `deleteWord(word)` - Remove word (O(m) time)

**Use Cases:** Autocomplete, spell checking, IP routing

---

## Question 2: PATRICIA TREE

**Files:** `question2.cpp`, `Q2` (executable), `reflection.md`

Space-optimized Trie where edges store string prefixes instead of single characters.

**Key Features:**
- Edge compression reduces space
- Longest Common Prefix (LCP) for edge splitting
- Same O(m) operations as Trie, but less memory

**When to Use:** Many words with common prefixes, memory-constrained systems

---

## Question 3: MANACHER'S ALGORITHM

**Files:** `question3.cpp`, `Q3` (executable), `reflection.md`

Find longest palindromic substring in O(n) time using mirror property.

**Three Approaches:**
- Brute Force: O(n³) - check all substrings
- Dynamic Programming: O(n²) - use recurrence relations
- **Manacher's:** O(n) - exploit palindrome symmetry ⭐

**Key Insight:** Transform string with separators to handle odd/even palindromes uniformly. Use "right pointer" tracking for O(n) amortized complexity.

---

## Quick Start

```bash
# Compile all
g++ -o question_1/Q1 question_1/question1.cpp
g++ -o question_2/Q2 question_2/question2.cpp
g++ -o question_3/Q3 question_3/question3.cpp

# Run
./question_1/Q1
./question_2/Q2
./question_3/Q3
```

---

## Complexity Summary

| Algorithm | Time | Space | Notes |
|-----------|------|-------|-------|
| Trie | O(m) | O(n·m) | n=words, m=length |
| PATRICIA | O(m) | O(n) to O(n·m) | Space optimized |
| Manacher | O(n) | O(n) | Linear time! |

---

## File Structure

```
practical_6/
├── question_1/
│   ├── question1.cpp
│   ├── Q1
│   └── reflection.md
├── question_2/
│   ├── question2.cpp
│   ├── Q2
│   └── reflection.md
├── question_3/
│   ├── question3.cpp
│   ├── Q3
│   └── reflection.md
└── README.md
```

**Status:** ✓ All implementations complete and tested
