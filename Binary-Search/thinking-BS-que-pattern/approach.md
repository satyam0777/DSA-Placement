---

## How to Think and Proceed with Binary Search Problems (Step-by-Step)

### Step 1: Analyze the Problem Statement

- Is the data **sorted** or can you define a **monotonic** (always increasing/decreasing) search space?
- Are you searching for a value, an index, or a minimum/maximum that satisfies a condition?

---

### Step 2: Define the Search Space

- For arrays: Usually `low = 0`, `high = n-1`.
- For "search on answer": `low` and `high` are the minimum and maximum possible values (not indices).

---

### Step 3: Identify the Predicate/Condition

- What is the **condition** that splits the search space?
    - For classic search: `arr[mid] == target`
    - For first/last occurrence: `arr[mid] == target` but keep searching left/right
    - For "search on answer": Does `mid` satisfy the problem's requirement?

---

### Step 4: Decide How to Update Pointers

- If the condition is **not** met, should you move `low` up or `high` down?
- For minimum/first occurrence: often move `high = mid - 1` on match.
- For maximum/last occurrence: often move `low = mid + 1` on match.

---

### Step 5: Handle Edge Cases

- What if the element is not found?
- What if there are duplicates?
- What if the array is rotated or infinite?

---

### Step 6: Dry Run with a Small Example

- Write down a small input and simulate your logic step by step.
- Check how `low`, `high`, and `mid` change.

---

### Step 7: Write a General Template

- Use a standard binary search template and adapt it to your problem.
- For "search on answer", use a helper function to check the predicate.

---

### Step 8: Test and Debug

- Test with edge cases: empty array, single element, all elements same, target not present, etc.
- Check for off-by-one errors.

---

**In Summary:**  
- Always start by asking: "Is the search space sorted or monotonic?"
- Define what you are searching for (value, index, min/max, property).
- Identify the condition that splits the search space.
- Carefully update your pointers and handle edge cases.
- Dry run your logic before coding the full solution.

---

**I try to follow the same pattern leanring as well as explaination ,like Aditya Verma Sir , if someone has any doubt then watch his playlist , and if anyone want to add his own concept the make PR ,If needed then i merge it**
