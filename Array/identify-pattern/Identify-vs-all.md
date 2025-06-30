# How to Identify Which DSA Concept or Technique to Use

---

## 1. General Approach

- **Read the problem statement carefully.**
- **Look for keywords** and patterns in the requirements.
- **Ask yourself:** What is being asked? (sum, count, existence, maximum, minimum, subarray, substring, etc.)
- **Think about brute force:** Is it too slow? What is the bottleneck?
- **Recall standard problems:** Does this look like a classic problem you’ve seen before?

---

## 2. Key Concepts, When to Use, and How to Identify

---

### a. Hashing / Frequency Counting

**When to Use:**
- Need to check existence, count frequency, or group elements quickly.
- Problems with "find if exists", "count", "duplicates", "anagrams", "intersection".

**Keywords:**  
frequency, count, exists, duplicate, anagram, group, intersection

**Typical Data Structures:**  
`unordered_map`, `unordered_set`

---

### b. Prefix Sum

**When to Use:**
- Multiple queries for sum of subarrays/ranges.
- Need to count subarrays with a given sum (often with hashing).
- Cumulative sum/frequency/count problems.

**Keywords:**  
range sum, subarray sum, cumulative, prefix, suffix, sum between indices

**Typical Data Structures:**  
Array for prefix sums, sometimes combined with hash maps.

---

### c. Kadane’s Algorithm

**When to Use:**
- Find the maximum sum of a contiguous subarray.
- Sometimes for maximum product subarray or variations.

**Keywords:**  
maximum subarray sum, largest sum, contiguous, subarray

**Typical Data Structures:**  
Simple variables, sometimes arrays for indices.

---

### d. Sliding Window

**When to Use:**
- Find max/min/sum/length of subarray/substring with a property.
- Window is contiguous and size is fixed or variable.
- Often used for substrings/subarrays with unique/distinct elements, or sum/average constraints.

**Keywords:**  
window, subarray, substring, at most/exactly/at least k, longest/shortest, contiguous

**Typical Data Structures:**  
Two pointers, sets/maps for variable window.

---

### e. Two Pointer Technique

**When to Use:**
- Array/string is sorted or can be sorted.
- Need to find pairs/triplets/subarrays with a property (sum, difference, etc.).
- Problems like pair sum, remove duplicates, reverse, partition.

**Keywords:**  
pair, triplet, sorted, sum, difference, reverse, partition, move zeros

**Typical Data Structures:**  
Two indices/pointers.

---

### f. Other Concepts

- **Binary Search:** When searching for an element or answer in a sorted array/range.
- **Stack/Queue:** For problems with "previous/next greater/smaller", balanced parentheses, BFS/DFS.
- **Heap/Priority Queue:** For always getting min/max efficiently (kth largest, running median).
- **Dynamic Programming:** For optimal substructure and overlapping subproblems.

---

## 3. Key Differences and How to Choose

| Concept         | Use When...                                              | Typical Problems/Keywords                        |
|-----------------|---------------------------------------------------------|--------------------------------------------------|
| Hashing         | Fast lookup/count/grouping                              | Frequency, existence, duplicates, anagrams       |
| Prefix Sum      | Many range sum queries, cumulative properties           | Range sum, subarray sum, cumulative, prefix      |
| Kadane’s        | Max sum of contiguous subarray                          | Maximum subarray sum, largest sum, contiguous    |
| Sliding Window  | Contiguous subarray/substring, fixed/variable window    | Window, at most/exactly k, longest/shortest      |
| Two Pointer     | Sorted data, pairs/triplets/subarrays with property     | Pair sum, reverse, partition, remove duplicates  |
| Binary Search   | Search in sorted array/range, optimization              | Find element, kth smallest, min/max answer       |
| Stack/Queue     | Previous/next greater/smaller, BFS/DFS, parentheses     | Span, monotonic stack, level order traversal     |
| Heap            | Always get min/max, k-th largest/smallest               | Running median, top k elements                   |
| DP              | Optimal substructure, overlapping subproblems           | Subset sum, knapsack, edit distance, LIS         |

---

## 4. How to Decide in Practice

1. **Is the array sorted or can it be sorted?**  
   → Two pointer, binary search, or sorting-based approaches.

2. **Are you asked about subarrays/substrings with a property?**  
   → Sliding window, prefix sum, or Kadane’s.

3. **Do you need to count or check existence/grouping?**  
   → Hashing/frequency map.

4. **Are there multiple range queries?**  
   → Prefix sum, segment tree.

5. **Is it about maximum/minimum in a window or subarray?**  
   → Sliding window, heap, or monotonic queue.

6. **Is it about optimal choices, overlapping subproblems?**  
   → Dynamic programming.

---

**Summary:**  
- Read the problem and extract keywords.
- Map the keywords and requirements to standard DSA concepts.
- Think about brute force and how to optimize.
- Choose the technique that fits the problem’s structure and constraints.

---