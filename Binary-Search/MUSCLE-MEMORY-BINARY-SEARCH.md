# 🎯 BINARY SEARCH - MUSCLE MEMORY EDITION


---

## ⚡ 3-SECOND RECOGNITION

**Ask 3 Questions:**
1. Is array **SORTED/MONOTONIC**? ✅
2. Looking for **TARGET/BOUNDARY**? ✅
3. Can eliminate **HALF** each step? ✅

**If all 3 YES → BINARY SEARCH! 🎯**

---

## 🔥 MAGIC KEYWORDS

| **See This** | **Pattern** | **Use This** |
|--------------|-------------|--------------|
| "Sorted array" + "Find element" | Classic BS | Standard template |
| "First occurrence" / "Lower bound" | Boundary (Left) | `high = mid - 1` on match |
| "Last occurrence" / "Upper bound" | Boundary (Right) | `low = mid + 1` on match |
| "Minimum capacity" / "Maximum distance" | BS on Answer | Define range, check valid |
| "Rotated sorted array" | Modified BS | Find sorted half |
| "Square root" / "Nth root" | BS on Answer | Check mid² vs n |
| "Peak element" | Modified BS | Compare neighbors |

---

## 📝 THE 3 GOLDEN TEMPLATES

### **TEMPLATE 1: CLASSIC BINARY SEARCH**
```cpp
int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    
    return -1;
}
```
**Mantra:** *"Equal found, Less right, More left"*  
**Time:** O(log n) | **Space:** O(1)

---

### **TEMPLATE 2A: FIRST OCCURRENCE (GO LEFT)**
```cpp
int firstOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            ans = mid;
            high = mid - 1;  // 🔥 Keep searching LEFT
        }
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    
    return ans;
}
```
**Mantra:** *"Found? Save it! But check LEFT!"*  
**Time:** O(log n) | **Space:** O(1)

---

### **TEMPLATE 2B: LAST OCCURRENCE (GO RIGHT)**
```cpp
int lastOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            ans = mid;
            low = mid + 1;  // 🔥 Keep searching RIGHT
        }
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    
    return ans;
}
```
**Mantra:** *"Found? Save it! But check RIGHT!"*  
**Time:** O(log n) | **Space:** O(1)

---

### **TEMPLATE 3: BINARY SEARCH ON ANSWER**
```cpp
bool isValid(vector<int>& arr, int mid, int k) {
    // Check if 'mid' satisfies condition
    // Return true/false
}

int bsOnAnswer(vector<int>& arr, int k) {
    int low = minimum_possible;  // e.g., max element
    int high = maximum_possible; // e.g., sum
    int result = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (isValid(arr, mid, k)) {
            result = mid;
            high = mid - 1;  // For minimum, search left
            // low = mid + 1;  // For maximum, search right
        } else {
            low = mid + 1;
        }
    }
    
    return result;
}
```
**Mantra:** *"Define range, check mid works, adjust!"*  
**Time:** O(n log(range)) | **Space:** O(1)

---

## 🎯 DECISION TREE

```
                Binary Search Problem?
                         |
        ┌────────────────┼────────────────┐
        |                |                |
    Sorted array?    Finding value?    Rotated?
        |                |                |
        v                v                v
   Exact match?     Min/Max value?    One half sorted?
    /      \          /      \             |
  YES      NO       YES      NO            v
   |        |        |        |        Modified BS
Classic  First/Last  |        |        (Find sorted half)
   BS    Boundary    |        |
         (GO LEFT    v        v
          or RIGHT)  BS on   Other
                    Answer  patterns
```

---

## 💡 THE GOLDEN FORMULAS

### **Formula 1: Avoid Overflow**
```cpp
// ❌ WRONG:
int mid = (low + high) / 2;

// ✅ CORRECT:
int mid = low + (high - low) / 2;
```

### **Formula 2: Count Occurrences**
```cpp
int count = lastOccurrence(arr, target) - firstOccurrence(arr, target) + 1;
```

### **Formula 3: Floor and Ceiling**
```cpp
// Floor = Largest ≤ target
// Keep going right when arr[mid] ≤ target

// Ceiling = Smallest ≥ target  
// Keep going left when arr[mid] ≥ target
```

---

## 🔄 PATTERN COMPARISON

| **Aspect** | **Classic BS** | **Boundary BS** | **BS on Answer** |
|------------|----------------|-----------------|------------------|
| **When match found** | Return immediately | Store & continue | N/A |
| **Search space** | Array indices | Array indices | Value range |
| **After match** | Stop | Go left/right | Check validity |
| **Use for** | Find element | Find boundary | Find min/max |
| **Pointer update** | Normal | Special | Based on valid |

---

## 🎯 TOP 8 PROBLEMS (Target Times)

| # | **Problem** | **Pattern** | **Time** | **⭐** |
|---|-------------|-------------|----------|--------|
| 1 | Classic Binary Search | 1 | 3 min | ⭐⭐⭐⭐⭐ |
| 2 | First & Last Position | 2A+2B | 7 min | ⭐⭐⭐⭐⭐ |
| 3 | Search Rotated Array | Modified | 8 min | ⭐⭐⭐⭐⭐ |
| 4 | Square Root (Floor) | 3 | 5 min | ⭐⭐⭐⭐⭐ |
| 5 | Allocate Minimum Pages | 3 | 12 min | ⭐⭐⭐⭐⭐ |
| 6 | Find Peak Element | Modified | 6 min | ⭐⭐⭐⭐ |
| 7 | Count Occurrences | 2A+2B | 8 min | ⭐⭐⭐⭐ |
| 8 | Floor and Ceiling | 2 | 10 min | ⭐⭐⭐⭐ |

---

## 🎤 INTERVIEW SCRIPTS

### **Recognition Script:**
> "Sir, I notice [sorted array / finding min-max value]. This is [Pattern 1/2/3] binary search. Time O(log n), Space O(1)."

### **Classic BS Script:**
> "Sir, array is sorted. I'll use standard binary search - compare with mid, eliminate half at each step."

### **Boundary BS Script:**
> "Sir, for [first/last] occurrence, when I find target, I don't stop - I keep searching [left/right] for better answer."

### **BS on Answer Script:**
> "Sir, I'm not searching in array - I'm binary searching on answer range. For each mid, I check if it works using helper function."

---

## 💪 MANTRAS (Say 10x!)

```
1. "mid = low + (high - low) / 2" (Avoid overflow!)
2. "Found? Save! Go LEFT for first!"
3. "Found? Save! Go RIGHT for last!"
4. "Define range, check valid, adjust!"
5. "Eliminate HALF at each step!"
6. "Sorted = Binary Search possible!"
7. "Count = last - first + 1"
8. "One half always sorted in rotated array!"
```

---

## 💡 MEMORY HOOKS

### **📖 Dictionary Search**
> Classic BS = Finding word in dictionary  
> Don't start page 1! Open middle, check before/after!

### **📅 First/Last Day**
> Boundary BS = Finding first sick day in calendar  
> Found one? Check earlier days (go left)!

### **🎒 Load Distribution**
> BS on Answer = Distributing work fairly  
> Try capacity, check if works, adjust!

### **🔄 Rotated Clock**
> Rotated Array = Clock starting from random hour  
> Numbers still in order, just rotated!

---

## 🌳 VISUAL PATTERNS

### **Classic BS Movement:**
```
[1, 2, 3, 4, 5, 6, 7]
       ↑ mid=4
target=6 > 4? Go RIGHT →
             [5, 6, 7]
                ↑ mid=6
Found! ✅
```

### **First Occurrence:**
```
[1, 2, 2, 2, 3, 4, 5]
       ↑ Found 2!
But check LEFT ← for earlier 2
    ↑ Found earlier!
Keep going ← until no more
```

### **BS on Answer:**
```
Range: [90 ........... 203]
              ↑ Try 146
Works? ✅ Try smaller ←
         ↑ Try 117
Works? ✅ Try smaller ←
       ↑ Try 103
Works? ❌ Need bigger →
Answer: 113
```

---

## ❌ COMMON MISTAKES (AVOID!)

| **Mistake** | **Fix** |
|-------------|---------|
| ❌ `mid = (low + high) / 2` | ✅ `mid = low + (high - low) / 2` |
| ❌ `while (low < high)` can loop | ✅ `while (low <= high)` |
| ❌ Stop when found (for boundary) | ✅ Keep searching left/right |
| ❌ `low = mid` (infinite loop) | ✅ `low = mid + 1` (always move) |
| ❌ Forget to store answer | ✅ `ans = mid` before continuing |

---

## 📊 COMPLEXITY REFERENCE

| **Pattern** | **Time** | **Space** | **When** |
|-------------|----------|-----------|----------|
| Classic BS | O(log n) | O(1) | Find exact element |
| Boundary BS | O(log n) | O(1) | Find first/last |
| BS on Answer | O(n log R) | O(1) | Find min/max value |
| Rotated Array | O(log n) | O(1) | Modified sorted |

*R = range of answer space*

---

## 🎯 ONE-PAGE PRINTABLE

```
╔═══════════════════════════════════════════════════════════╗
║           BINARY SEARCH - WALLET CARD                     ║
╠═══════════════════════════════════════════════════════════╣
║ RECOGNITION (3 questions):                                ║
║   Q1: Sorted/Monotonic? ✅                                ║
║   Q2: Target/Boundary? ✅                                 ║
║   Q3: Eliminate half? ✅                                  ║
║   All YES → BINARY SEARCH!                                ║
╠═══════════════════════════════════════════════════════════╣
║ TEMPLATE 1: CLASSIC (Find Element)                        ║
║   while(low <= high) {                                    ║
║     mid = low + (high - low) / 2;                         ║
║     if(arr[mid] == target) return mid;                    ║
║     else if(arr[mid] < target) low = mid + 1;             ║
║     else high = mid - 1;                                  ║
║   }                                                       ║
║   Mantra: "Equal found, Less right, More left"            ║
╠═══════════════════════════════════════════════════════════╣
║ TEMPLATE 2A: FIRST OCCURRENCE (Go LEFT)                   ║
║   int ans = -1;                                           ║
║   while(low <= high) {                                    ║
║     mid = low + (high - low) / 2;                         ║
║     if(arr[mid] == target) {                              ║
║       ans = mid;                                          ║
║       high = mid - 1;  // Keep searching LEFT             ║
║     }                                                     ║
║     else if(arr[mid] < target) low = mid + 1;             ║
║     else high = mid - 1;                                  ║
║   }                                                       ║
║   Mantra: "Found? Save! Check LEFT!"                      ║
╠═══════════════════════════════════════════════════════════╣
║ TEMPLATE 2B: LAST OCCURRENCE (Go RIGHT)                   ║
║   int ans = -1;                                           ║
║   while(low <= high) {                                    ║
║     mid = low + (high - low) / 2;                         ║
║     if(arr[mid] == target) {                              ║
║       ans = mid;                                          ║
║       low = mid + 1;  // Keep searching RIGHT             ║
║     }                                                     ║
║     else if(arr[mid] < target) low = mid + 1;             ║
║     else high = mid - 1;                                  ║
║   }                                                       ║
║   Mantra: "Found? Save! Check RIGHT!"                     ║
╠═══════════════════════════════════════════════════════════╣
║ TEMPLATE 3: BS ON ANSWER                                  ║
║   int low = min_possible, high = max_possible;            ║
║   int result = -1;                                        ║
║   while(low <= high) {                                    ║
║     mid = low + (high - low) / 2;                         ║
║     if(isValid(mid)) {                                    ║
║       result = mid;                                       ║
║       high = mid - 1; // For minimum                      ║
║     } else low = mid + 1;                                 ║
║   }                                                       ║
║   Mantra: "Range, check valid, adjust!"                   ║
╠═══════════════════════════════════════════════════════════╣
║ GOLDEN FORMULAS:                                          ║
║   • mid = low + (high - low) / 2  (avoid overflow)        ║
║   • count = last - first + 1                              ║
║   • Always: while(low <= high)                            ║
║   • Always: low = mid + 1 or high = mid - 1               ║
╠═══════════════════════════════════════════════════════════╣
║ KEYWORDS → PATTERN:                                       ║
║   "Find element" → Classic BS                             ║
║   "First/Last" → Boundary BS (Go LEFT/RIGHT)              ║
║   "Min/Max capacity" → BS on Answer                       ║
║   "Rotated" → Modified BS (Find sorted half)              ║
║   "Square root" → BS on Answer                            ║
╠═══════════════════════════════════════════════════════════╣
║ COMPLEXITY:                                               ║
║   All patterns: O(log n) time, O(1) space                 ║
║   BS on Answer: O(n log R) where R = range                ║
╠═══════════════════════════════════════════════════════════╣
║ COMMON MISTAKES:                                          ║
║   ❌ (low + high) / 2 → ✅ low + (high - low) / 2        ║
║   ❌ Stop when found → ✅ Keep searching (boundary)      ║
║   ❌ low = mid → ✅ low = mid + 1 (move always)          ║
╠═══════════════════════════════════════════════════════════╣
║ MANTRAS:                                                  ║
║   "Sorted = BS possible!"                                 ║
║   "Eliminate HALF each step!"                             ║
║   "Found? Save! Go LEFT/RIGHT!"                           ║
║   "Define range, check valid!"                            ║
╚═══════════════════════════════════════════════════════════╝
```



---

*Practice these templates until they write themselves. That's muscle memory!* ✨
