#  TWO POINTER - MUSCLE MEMORY EDITION (ONE-PAGE PRINTABLE)

---

## 📋 3-SECOND RECOGNITION

**Ask 3 Questions:**
1. Is array **SORTED**? ✅
2. Need **PAIRS** or **IN-PLACE** modification? ✅  
3. Need **O(1) space**? ✅

**If 2+ YES → TWO POINTER! 🎯**

---

## 🎨 THREE TYPES (Choose in 3 seconds)

```
TYPE 1: OPPOSITE ⬅️➡️
[1, 2, 3, 4, 5, 6, 7]
 ↑                 ↑
left              right
 →                ←
Use for: Sorted, Pairs, Reverse, Palindrome

TYPE 2: SAME ➡️➡️
[1, 2, 3, 4, 5, 6, 7]
 ↑
slow (collects)
 ↑
fast (explores)
Use for: Remove, Move, In-place

TYPE 3: FIXED 🎯
[1, 2, 3, 4, 5, 6, 7]
 ↑  ↑           ↑
 i  left       right
Use for: 3Sum, Triplets
```

---

## 📝 THREE TEMPLATES (Write from memory in 7 minutes!)

### **TEMPLATE A: OPPOSITE** ⬅️➡️ (2 min)

```cpp
int left = 0, right = n - 1;

while (left < right) {  // NOT <=
    int result = arr[left] + arr[right];
    
    if (result == target) {
        return true;  // Found!
    }
    else if (result < target) {
        left++;   // Need larger
    }
    else {
        right--;  // Need smaller
    }
}

return false;
```

**Mantra:** *"Less left++, Equal found, More right--"*

---

### **TEMPLATE B: SAME** ➡️➡️ (2 min)

```cpp
int slow = 0;

for (int fast = 0; fast < n; fast++) {
    if (condition_met(arr[fast])) {  // Should I keep?
        arr[slow] = arr[fast];  // or swap
        slow++;
    }
}

return slow;  // New length
```

**Mantra:** *"fast explores ALL, slow collects VALID"*

**Common Conditions:**
- Remove Duplicates: `arr[fast] != arr[slow-1]`
- Move Zeros: `arr[fast] != 0`
- Remove Element: `arr[fast] != val`

---

### **TEMPLATE C: FIXED** 🎯 (3 min)

```cpp
sort(arr.begin(), arr.end());  // MUST SORT!
vector<vector<int>> result;

for (int i = 0; i < n - 2; i++) {
    // Skip duplicates
    if (i > 0 && arr[i] == arr[i-1]) continue;
    
    // Two pointer on rest
    int left = i + 1, right = n - 1;
    int target = -arr[i];
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        
        if (sum == target) {
            result.push_back({arr[i], arr[left], arr[right]});
            
            // Skip duplicates
            while (left < right && arr[left] == arr[left+1]) left++;
            while (left < right && arr[right] == arr[right-1]) right--;
            
            left++;
            right--;
        }
        else if (sum < target) left++;
        else right--;
    }
}

return result;
```

**Mantra:** *"Sort → Fix → Two Pointer → Skip Duplicates"*

---

## 🔥 MAGIC KEYWORDS

| Keyword | Type to Use |
|---------|-------------|
| "Sorted array" | OPPOSITE ⬅️➡️ |
| "Pair with sum" | OPPOSITE ⬅️➡️ |
| "Remove duplicates" | SAME ➡️➡️ |
| "Move zeros" | SAME ➡️➡️ |
| "Reverse" | OPPOSITE ⬅️➡️ |
| "Palindrome" | OPPOSITE ⬅️➡️ |
| "In-place" | SAME ➡️➡️ |
| "Three sum" | FIXED 🎯 |
| "Triplets" | FIXED 🎯 |

---

## 🎯 TOP 8 PROBLEMS (With Target Times)

1. **Two Sum (sorted)** - 5 min ⭐⭐⭐⭐⭐
2. **Remove Duplicates** - 3 min ⭐⭐⭐⭐⭐
3. **Move Zeros** - 4 min ⭐⭐⭐⭐⭐
4. **Valid Palindrome** - 5 min ⭐⭐⭐⭐⭐
5. **Container Water** - 6 min ⭐⭐⭐⭐
6. **Three Sum** - 10 min ⭐⭐⭐⭐
7. **Reverse Array** - 2 min ⭐⭐⭐⭐⭐
8. **Sort Colors** - 7 min ⭐⭐⭐⭐

---

## 📊 COMPLEXITY

| Type | Time | Space | Why O(n)? |
|------|------|-------|-----------|
| Opposite | O(n) | O(1) | Each pointer moves ≤n times |
| Same | O(n) | O(1) | Single pass with two pointers |
| Fixed | O(n²) | O(1) | Outer O(n) × Inner O(n) |

---

## ❌ COMMON MISTAKES

| Mistake | Correct |
|---------|---------|
| `while (left <= right)` | `while (left < right)` |
| No sort for 3Sum | `sort()` first! |
| Not skip duplicates | Skip with `if (i>0 && arr[i]==arr[i-1])` |
| Wrong pointer move | Less → left++, More → right-- |

---

## 🎤 INTERVIEW SCRIPT (Say This!)

**Recognition:**
> "Sir, I notice the array is sorted and we need pairs. Two pointer reduces O(n²) to O(n)!"

**Choosing Type:**
> "I'll use [OPPOSITE/SAME/FIXED] because [REASON]"

**Movement Logic:**
> "Move left when need larger value, right when need smaller"

**Complexity:**
> "Time O(n), Space O(1)"

---

## 💪 MUSCLE MEMORY DRILLS

### **Drill 1: Write Templates Blind**
- Close this file
- Write all 3 templates from memory
- **Repeat 5 times until 100% accurate!**
- **Target: 7 minutes for all 3**

### **Drill 2: Instant Recognition**
Read problem → Identify type in 3 seconds:
- "Find pair sum k in sorted" → **OPPOSITE** ✅
- "Remove duplicates in-place" → **SAME** ✅
- "Find triplets sum zero" → **FIXED** ✅

### **Drill 3: Recite Mantras**
Say 10 times each:
1. **Opposite:** "Less left++, Equal found, More right--"
2. **Same:** "fast explores ALL, slow collects VALID"
3. **Fixed:** "Sort → Fix → Pointer → Skip Duplicates"

---

## 💡 MEMORY HOOKS

### **Hook 1: Dance Floor** 🕺💃
- **Opposite:** Two people from ends meeting in middle
- **Same:** One exploring, other following and collecting

### **Hook 2: Target Practice** 🎯
- **Opposite:** Adjust aim (too low? higher, too high? lower)
- **Same:** Collector gathering valid targets

### **Hook 3: Library Shelf** 📚
- **Opposite:** Searching from both ends
- **Same:** Organizing (slow=organized, fast=exploring)

---


## 📌 DECISION TREE (Visual Guide)

```
START: See Problem
    ↓
Q: Is array SORTED?
    ↓
YES → Q: Looking for PAIRS?
       ↓
     YES → OPPOSITE ⬅️➡️
       ↓
     NO → Q: In-place modify?
            ↓
          YES → SAME ➡️➡️

Q: Looking for TRIPLETS?
    ↓
YES → FIXED 🎯
```

---

## 🎓 WHY TWO POINTER IS O(n)?

**Key Insight:**
```
Brute Force (Nested Loops):
for i in array:
    for j in array:
        check pair[i,j]
Total: n × n = O(n²) ❌

Two Pointer (Smart Elimination):
left = 0, right = n-1
while left < right:
    if valid: return
    elif need_more: left++
    else: right--
Total moves: n + n = O(n) ✅

Speedup: n² / n = n times faster!
```

---

## 🏆 FINAL WISDOM

**Before coding, take 30 seconds to:**
1. Identify pattern (sorted? pairs?)
2. Choose correct type
3. Explain approach

**Then code confidently with template!**

> **"Two pointers eliminate possibilities based on smart comparison, not brute force checking!"**

---

**🎯 You got this! Templates are muscle memory now! 💪**

**All the best! 🚀**

---

*Print this page. Review daily. Success guaranteed in 7 days!*
