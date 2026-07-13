# 🚀 DSA C++ Learning Journey

This repository contains my Data Structures and Algorithms (DSA) practice in C++.

The goal is to build strong problem-solving skills, understand patterns, and solve LeetCode-style problems.

---

# 📚 Progress Tracker

## ✅ Basics of C++

Folder:

```
Learn C++
```

Topics Covered:

- Variables
- Data Types
- Conditions
- Loops
- Functions
- Arrays
- Basic C++ Syntax
- Object Oriented Programming Basics


Progress:

```
██████████ 100%
```

---

# 🧩 Data Structures & Algorithms

## 1. Arrays

Folder:

```
DSA/Array
```

Topics:

- Array traversal
- Searching
- Sorting basics
- Prefix Sum
- Two Pointer techniques

Status:

```
In Progress
```

---

# 2. Two Pointers Pattern

Folder:

```
DSA/Pattern: Two Pointers
```

Concept:

Two pointers technique is used to solve problems where we maintain two indexes and move them based on conditions.

Examples:

- Pair Sum
- Removing duplicates
- Reverse array/string


Status:

```
Completed Basics ✅
```

---

# 3. Sliding Window Pattern ⭐

Folder:

```
DSA/Sliding Window
```

Sliding Window is one of the most important interview patterns.

The idea:

Instead of checking every possible subarray/substring, maintain a moving window using two pointers.

```
left  ---> Window <--- right
```

---

## Problems Solved

### ✅ Fruit Into Basket

Concept:

- Longest subarray with at most 2 different fruits
- Frequency counting
- Variable size window


---

### ✅ Longest Substring With K Uniques

Concept:

- Maintain character frequency
- Expand window
- Shrink when condition breaks


---

### ✅ Maximum Sum Subarray of Size K

Concept:

Fixed size sliding window.

Example:

```
[1 2 3] 4 5

Window size = 3
```

Remove old element and add new element.


---

### ✅ Minimum Size Subarray Sum

Concept:

Find smallest window whose sum is greater than or equal to target.


---

### ✅ Minimum Window Substring ⭐

LeetCode 76

Concepts learned:

- Sliding Window
- Frequency Array
- Two Pointer
- Character counting


Important Logic:

```
Expand window using right pointer

↓

Window becomes valid

↓

Shrink window using left pointer

↓

Store minimum answer
```

Status:

```
Completed ✅
```

---

# Sliding Window Template

Most problems follow this pattern:

```cpp
int left = 0;

for(int right = 0; right < n; right++)
{

    // Add element to window


    while(condition)
    {

        // Remove element from window

        left++;

    }

    // Update answer
}
```

---

# Current Learning Roadmap

```
✅ C++ Basics

✅ Arrays Basics

✅ Two Pointer Pattern

🔄 Sliding Window Pattern

⬜ Stack

⬜ Queue

⬜ Linked List

⬜ Recursion

⬜ Backtracking

⬜ Binary Search

⬜ Trees

⬜ Graphs

⬜ Dynamic Programming
```

---

# LeetCode Progress

## Sliding Window Problems

| Problem | Status |
|---|---|
| Fruit Into Basket | ✅ |
| Longest Substring With K Unique Characters | ✅ |
| Maximum Sum Subarray Size K | ✅ |
| Minimum Size Subarray Sum | ✅ |
| Minimum Window Substring | ✅ |

---

# Important Patterns Learned

## Two Pointer

Used when:

- Array/String is sorted
- Need pair comparison
- Need left and right movement


## Sliding Window

Used when:

- Finding longest/shortest substring
- Finding continuous subarray
- Need frequency/count tracking


---

# Repository Structure

```
DSA.CPP
│
├── DSA
│   │
│   ├── Array
│   │
│   ├── Pattern: Two Pointers
│   │
│   ├── Sliding Window
│       │
│       ├── Fruit into Basket
│       ├── Longest Substring with K Uniques
│       ├── Max Sum Subarray of Size K
│       ├── Minimum Size Subarray Sum
│       └── Minimum Window Substring
│
└── Learn C++
    │
    ├── Day 1
    ├── Day 2
    ├── Day 3 (Conditional)
    ├── Day 4 OOPS
    ├── Day 5 Arrays
    └── Day 6 Functions
```

---

# Goal 🎯

- Solve DSA problems consistently
- Understand patterns instead of memorizing solutions
- Improve problem-solving skills
- Prepare for coding interviews

---

## Daily Progress

Keep learning. Keep solving. 🚀