# 🎯 BASIC ARRAY - ONE-PAGE PRINTABLE SUMMARY
*Muscle Memory Edition - Print & Keep in Wallet!*

---

## ⚡ 3-SECOND RECOGNITION

**Ask yourself these 3 questions:**
1. Is it a **fixed collection** of elements? → YES = Array
2. Need **sequential scanning** or **index access**? → YES = Array
3. Are elements of the **same type**? → YES = Array

---

## 🔑 MAGIC KEYWORDS → PATTERN MAPPING

| **You See This** | **Think This** | **Use This** |
|------------------|----------------|--------------|
| "Find max/min" | Single pass scan | Template 1 |
| "Reverse" | Two pointer | Template 2 |
| "Search element" | Linear/Binary | Template 3 |
| "Remove duplicates" | HashSet | Template 4 |
| "Rotate by k" | Triple reversal | Template 5 |
| "Sum/Average" | Accumulator | Single loop |
| "Second largest" | Two variables | Single pass |
| "Count frequency" | HashMap | O(n) scan |

---

## 💎 THE GOLDEN RULES

```
╔════════════════════════════════════════════════════╗
║  1. Array Name ≡ Pointer to First Element         ║
║     arr ≡ &arr[0]                                  ║
║                                                    ║
║  2. Address = Base + (index × sizeof(element))    ║
║                                                    ║
║  3. Arrays ALWAYS Passed by Reference             ║
║     (No copy, changes affect original!)           ║
╚════════════════════════════════════════════════════╝
```

---

## 📝 ALL 5 TEMPLATES (Compact Form)

### **Template 1: Find Min/Max**
```cpp
int maxVal = arr[0];
for (int i = 1; i < n; i++) {
    if (arr[i] > maxVal) maxVal = arr[i];
}
// Mantra: "Assume first is best, then challenge!"
```

### **Template 2: Reverse Array (Two Pointer)**
```cpp
int left = 0, right = n - 1;
while (left < right) {
    swap(arr[left], arr[right]);
    left++; right--;
}
// Mantra: "Swap and move inward from both ends!"
```

### **Template 3: Linear Search**
```cpp
for (int i = 0; i < n; i++) {
    if (arr[i] == key) return i;
}
return -1;
// Mantra: "Scan left to right, return when found!"
```

### **Template 4: Remove Duplicates**
```cpp
unordered_set<int> seen;
int writeIndex = 0;
for (int i = 0; i < n; i++) {
    if (!seen.count(arr[i])) {
        seen.insert(arr[i]);
        arr[writeIndex++] = arr[i];
    }
}
return writeIndex;
// Mantra: "Seen it? Skip. New? Write!"
```

### **Template 5: Rotate Right by K**
```cpp
void reverse(int arr[], int s, int e) {
    while (s < e) swap(arr[s++], arr[e--]);
}

k = k % n;
reverse(arr, 0, n-1);    // Reverse all
reverse(arr, 0, k-1);    // Reverse first k
reverse(arr, k, n-1);    // Reverse rest
// Mantra: "Reverse whole, reverse parts!"
```

---

## 🎤 MANTRAS (Say 10x Before Coding!)

```
1. "Array = Contiguous Memory Block!"
2. "Index starts 0, ends n-1!"
3. "arr[i] ≡ *(arr + i)"
4. "Always passed by reference!"
5. "Two pointers for reversal!"
6. "HashSet for duplicates!"
7. "Single pass when possible!"
8. "Check bounds: 0 to n-1!"
```

---

## 🧩 5 PROBLEM PATTERNS AT A GLANCE

### **1. Find Min/Max** 
- **Pattern**: Single pass, track best
- **Time**: O(n) | **Space**: O(1)
- **Key**: Assume first, then challenge

### **2. Reverse Array**
- **Pattern**: Two pointer swap
- **Time**: O(n) | **Space**: O(1)
- **Key**: Swap from both ends inward

### **3. Linear Search**
- **Pattern**: Sequential scan
- **Time**: O(n) | **Space**: O(1)
- **Key**: Return immediately when found

### **4. Remove Duplicates**
- **Pattern**: HashSet + Write Index
- **Time**: O(n) | **Space**: O(n)
- **Key**: Track seen, write only unique

### **5. Rotate Array**
- **Pattern**: Triple reversal
- **Time**: O(n) | **Space**: O(1)
- **Key**: Reverse whole, then parts

---

## 🌳 DECISION TREE (Visual Flowchart)

```
                   Array Problem?
                         |
        ┌────────────────┼────────────────┐
        |                |                |
   Find Min/Max?    Need Reverse?    Need Search?
        |                |                |
   Single Pass      Two Pointer      Sorted?
   Compare Best    Swap Inward      /     \
   O(n), O(1)      O(n), O(1)     YES    NO
                                  /         \
                            Binary       Linear
                            O(log n)     O(n)
                            
                   Need Rotate?
                        |
                  Triple Reversal
                  Reverse All → Parts
                  O(n), O(1)
                  
              Remove Duplicates?
                        |
                 HashSet Tracking
                 Write Only Unique
                 O(n), O(n)
```

---

## 📊 COMPLEXITY CHEAT SHEET

| **Operation** | **Time** | **Space** | **Pattern** |
|---------------|----------|-----------|-------------|
| Access arr[i] | O(1) | - | Direct |
| Traverse | O(n) | O(1) | Loop |
| Linear Search | O(n) | O(1) | Sequential |
| Binary Search | O(log n) | O(1) | Divide & Conquer |
| Find Min/Max | O(n) | O(1) | Single pass |
| Reverse | O(n) | O(1) | Two pointer |
| Rotate | O(n) | O(1) | Triple reversal |
| Remove Dup | O(n) | O(n) | HashSet |
| Sort | O(n log n) | O(1) | Quick/Merge |

---

## 🎯 TOP 5 PROBLEMS (With Target Times)

| # | **Problem** | **Pattern** | **Target** |
|---|-------------|-------------|------------|
| 1 | Find Min/Max | Single Pass | 3 min |
| 2 | Reverse Array | Two Pointer | 3 min |
| 3 | Linear Search | Sequential | 2 min |
| 4 | Remove Duplicates | HashSet | 5 min |
| 5 | Rotate by K | Triple Reversal | 7 min |

---

## 💬 INTERVIEW SCRIPT

**When you see array problem, say:**

1. **"Let me clarify constraints first:"**
   - Is array sorted?
   - Can I use extra space?
   - In-place modification allowed?
   - What's the range of n?

2. **"I'll think about approach before coding:"**
   - Need Min/Max? → Single pass
   - Need Reverse? → Two pointer
   - Need Search? → Linear or Binary
   - Need Remove Dup? → HashSet
   - Need Rotate? → Triple reversal

3. **"Let me do a quick dry run:"**
   - [Show 1-2 steps with example]
   - "This should work!"

4. **"Time complexity: O(?), Space: O(?)"**

5. **"Let me code this up..."**

---

## 🏋️ MUSCLE MEMORY DRILLS

### **Drill 1: Write Blind (5 min)**
Close eyes, write from memory:
- Two pointer reversal
- Triple reversal rotation
- Linear search

### **Drill 2: Pattern Recognition (3 min)**
See keyword → Identify pattern instantly:
- "Find max" → ?
- "Reverse" → ?
- "Rotate" → ?
- "Remove dup" → ?

### **Drill 3: Dry Run Speed (10 min)**
Pick any problem, dry run in 2 minutes max:
- Write initial state
- Show 2-3 steps
- Write final answer

---

## 🧠 MEMORY HOOKS

### 🎬 **Cinema Seats** = Array
- Row of seats = Contiguous memory
- Seat number = Index (0, 1, 2...)
- All seats same type = Same data type

### 📦 **Storage Boxes** = Array Access
- Box 0, Box 1, Box 2... = arr[0], arr[1], arr[2]
- Direct access to any box = O(1)

### 🚂 **Train Coaches** = Sequential
- Coach[0] → Coach[1] → Coach[2]
- Traverse left to right

### 🎢 **Roller Coaster** = Rotation
- Last person → First position
- Rotate right = Triple reversal

---

## ⚡ GOLDEN RULES (Commit to Memory!)

```
1. Always check bounds: 0 ≤ i < n
2. Two pointer beats extra array (space!)
3. HashSet for duplicates (O(1) lookup)
4. k % n for rotation (handle k > n)
5. Dry run with small example first!
```

---


## 📋 ONE-PAGE ASCII PRINTABLE

```
╔═══════════════════════════════════════════════════════════╗
║            BASIC ARRAY - WALLET CARD                      ║
╠═══════════════════════════════════════════════════════════╣
║ GOLDEN RULE: arr ≡ &arr[0] (Always by reference!)        ║
╠═══════════════════════════════════════════════════════════╣
║ TEMPLATE 1: Min/Max                                       ║
║   max = arr[0]; for (i=1; i<n; i++) if (arr[i]>max)...  ║
║                                                           ║
║ TEMPLATE 2: Reverse (Two Pointer)                        ║
║   L=0, R=n-1; while(L<R) swap(arr[L++], arr[R--]);      ║
║                                                           ║
║ TEMPLATE 3: Linear Search                                ║
║   for (i=0; i<n; i++) if (arr[i]==key) return i;        ║
║                                                           ║
║ TEMPLATE 4: Remove Duplicates                            ║
║   set<int> seen; writeIdx=0;                             ║
║   if (!seen.count(x)) { seen.insert(x); arr[w++]=x; }   ║
║                                                           ║
║ TEMPLATE 5: Rotate Right by K                            ║
║   k%=n; reverse(0,n-1); reverse(0,k-1); reverse(k,n-1); ║
╠═══════════════════════════════════════════════════════════╣
║ COMPLEXITY:                                               ║
║   Min/Max: O(n), O(1)                                    ║
║   Reverse: O(n), O(1)                                    ║
║   Search: O(n), O(1)                                     ║
║   Remove Dup: O(n), O(n)                                 ║
║   Rotate: O(n), O(1)                                     ║
╠═══════════════════════════════════════════════════════════╣
║ MANTRAS:                                                  ║
║   "Assume first is best!" (Min/Max)                      ║
║   "Swap and move inward!" (Reverse)                      ║
║   "Scan left to right!" (Search)                         ║
║   "Seen? Skip. New? Write!" (Duplicates)                 ║
║   "Reverse whole, reverse parts!" (Rotate)               ║
╠═══════════════════════════════════════════════════════════╣
║ INTERVIEW CHECKLIST:                                      ║
║   ✓ Clarify constraints (sorted? space? in-place?)       ║
║   ✓ Think approach before coding                         ║
║   ✓ Dry run with small example                           ║
║   ✓ State time/space complexity                          ║
║   ✓ Handle edge cases (n=0, n=1, k>n)                     ║
╚═══════════════════════════════════════════════════════════╝
```



---

*Print this page and keep it in your wallet for last-minute revision before interviews!* 📄✨

