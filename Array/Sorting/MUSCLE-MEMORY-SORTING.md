# 🎯 SORTING - ONE-PAGE PRINTABLE SUMMARY
*Muscle Memory Edition with Real-World Examples - Print & Keep in Wallet!*

---

## ⚡ 3-SECOND RECOGNITION

**Ask yourself these 3 questions:**
1. Do I need elements in **specific order**? → YES = Sorting
2. Is it **"Kth largest/smallest"** or **"closest pair"**? → YES = Sort first!
3. Do I see **"0s, 1s, 2s"** or **"three colors"**? → YES = Dutch Flag!

---

## 🌍 REAL-WORLD = INTERVIEW CONNECTION

| **Real-World Example** | **Problem Type** | **Use This** |
|------------------------|------------------|--------------|
| 📱 Phone contacts A-Z | Basic sort | `sort(arr.begin(), arr.end())` |
| 🛒 Products: Low→High | Sort ascending | `sort(arr.begin(), arr.end())` |
| 🏆 Leaderboard (High→Low) | Sort descending | `sort(arr.begin(), arr.end(), greater<int>())` |
| 🚦 Traffic lights (R,Y,G) | Dutch Flag (0,1,2) | 3-pointer technique |
| 📧 Merge email lists | Merge sorted arrays | Two pointer |
| 🎮 3rd highest score | Kth largest | Sort + arr[k-1] |
| 📏 Words by length | Custom comparator | Lambda function |
| 🎓 Rank list | Sort descending | `greater<int>()` |

---

## 💎 THE GOLDEN RULES

```
╔══════════════════════════════════════════════════════╗
║  1. ALWAYS use STL sort() in interviews!             ║
║     (Unless asked for specific algorithm)            ║
║                                                      ║
║  2. sort() = O(n log n) guaranteed                  ║
║     (IntroSort = Quick + Heap + Insertion)          ║
║                                                      ║
║  3. Dutch Flag (0,1,2) = O(n), O(1)                ║
║     MOST FAMOUS! Must know by heart!                 ║
║                                                      ║
║  4. After sorting → Binary Search, Two Pointer       ║
║     Sorting unlocks many optimizations!              ║
╚══════════════════════════════════════════════════════╝
```

---

## 📝 ALL 5 TEMPLATES (Compact Form)

### **Template 1: Basic Sort**
```cpp
// Ascending (Default)
sort(arr.begin(), arr.end());

// Descending
sort(arr.begin(), arr.end(), greater<int>());

// Real: Amazon products Low→High price
// Mantra: "sort() for ascending, greater<>() for descending!"
```

### **Template 2: Dutch National Flag (0s, 1s, 2s)** ⭐ MOST FAMOUS
```cpp
int low = 0, mid = 0, high = n - 1;
while (mid <= high) {
    if (arr[mid] == 0) {
        swap(arr[low], arr[mid]);
        low++; mid++;
    }
    else if (arr[mid] == 1) mid++;
    else {  // arr[mid] == 2
        swap(arr[mid], arr[high]);
        high--;  // Don't move mid!
    }
}

// Real: Sort traffic lights (Red, Yellow, Green)
// Mantra: "0→Left, 2→Right, 1→Stay!"
```

### **Template 3: Custom Comparator (Lambda)**
```cpp
// Sort by length
sort(words.begin(), words.end(), [](string a, string b) {
    return a.length() < b.length();
});

// Sort by frequency
sort(arr.begin(), arr.end(), [&](int a, int b) {
    if (freq[a] != freq[b]) return freq[a] > freq[b];
    return a < b;
});

// Real: Word game (short words first)
// Mantra: "Lambda for custom rules!"
```

### **Template 4: Merge Two Sorted Arrays**
```cpp
int i = 0, j = 0;
while (i < n && j < m) {
    if (a[i] <= b[j]) result.push(a[i++]);
    else result.push(b[j++]);
}
while (i < n) result.push(a[i++]);
while (j < m) result.push(b[j++]);

// Real: Merge two contact lists
// Mantra: "Two pointers, compare and merge!"
```

### **Template 5: Kth Largest/Smallest**
```cpp
// Kth Largest
sort(arr.begin(), arr.end(), greater<int>());
return arr[k - 1];

// Kth Smallest
sort(arr.begin(), arr.end());
return arr[k - 1];

// Real: Find 3rd highest scorer
// Mantra: "Sort then index!"
```

---

## 🎤 MANTRAS (Say 10x Before Coding!)

```
1. "sort() = IntroSort = O(n log n)!"
2. "Ascending default, greater<>() descending!"
3. "Dutch Flag: 0→left, 2→right, 1→middle!"
4. "Kth largest = arr[k-1] after descending sort!"
5. "Merge sorted = Two pointers!"
6. "Custom order = Lambda comparator!"
7. "Sorting enables Binary Search!"
8. "85-95% array problems need sorting!"
```

---

## 🧩 5 PROBLEM PATTERNS AT A GLANCE

### **1. Basic Sort** (E-commerce)
- **Real**: Product prices Low→High
- **Pattern**: STL sort()
- **Time**: O(n log n) | **Space**: O(log n)
- **Key**: `sort(arr.begin(), arr.end())`

### **2. Dutch Flag** (Traffic Lights) ⭐ SUPER FAMOUS
- **Real**: Sort Red, Yellow, Green signals
- **Pattern**: Three-way partitioning
- **Time**: O(n) | **Space**: O(1)
- **Key**: 3 pointers (low, mid, high)

### **3. Custom Comparator** (Word Game)
- **Real**: Sort words by length
- **Pattern**: Lambda function
- **Time**: O(n log n) | **Space**: O(log n)
- **Key**: `[](auto a, auto b) { return ... }`

### **4. Merge Sorted** (Contact Lists)
- **Real**: Combine two phone contacts
- **Pattern**: Two pointer
- **Time**: O(n+m) | **Space**: O(n+m)
- **Key**: Compare and pick smaller

### **5. Kth Largest** (Leaderboard)
- **Real**: 3rd place winner
- **Pattern**: Sort + Index
- **Time**: O(n log n) | **Space**: O(1)
- **Key**: arr[k-1] after sort

---

## 🌳 DECISION TREE (Visual Flowchart)

```
                Sorting Problem?
                      |
        ┌─────────────┼─────────────┐
        |             |             |
   Basic Sort?   Only 0,1,2?   Custom Order?
        |             |             |
   STL sort()   Dutch Flag     Lambda
   O(n log n)    O(n), O(1)   Comparator
                     ↓
              MOST FAMOUS!
              
        Merge Two?         Kth Largest?
            |                   |
        Two Pointer       Sort + Index
         O(n+m)            O(n log n)
```

---

## 📊 COMPLEXITY CHEAT SHEET

| **Operation** | **Time** | **Space** | **Real Example** |
|---------------|----------|-----------|------------------|
| STL sort() | O(n log n) | O(log n) | Phone contacts |
| Dutch Flag | O(n) | O(1) | Traffic lights |
| Merge sorted | O(n+m) | O(n+m) | Contact lists |
| Kth largest | O(n log n) | O(1) | Leaderboard |
| Custom comparator | O(n log n) | O(log n) | Word length |

---

## 🎯 TOP 5 PROBLEMS (With Target Times & Real Examples)

| # | **Problem** | **Real Example** | **Target** |
|---|-------------|------------------|------------|
| 1 | Basic Sort | 🛒 E-commerce prices | 2 min |
| 2 | Dutch Flag (0,1,2) | 🚦 Traffic lights | 5 min |
| 3 | Custom Comparator | 📏 Word game length | 4 min |
| 4 | Merge Sorted | 📱 Contact lists | 5 min |
| 5 | Kth Largest | 🏆 3rd place winner | 3 min |

---

## 💬 INTERVIEW SCRIPT

**When you see sorting problem, say:**

1. **"Let me identify the pattern:"**
   - Basic sort? → STL sort()
   - Only 0,1,2? → Dutch Flag
   - Custom criteria? → Lambda
   - Merge sorted? → Two pointer
   - Kth largest? → Sort + index

2. **"Let me explain my approach:"**
   - [Connect to real-world example]
   - "Like sorting Amazon products by price..."
   - "Like traffic light signals..."

3. **"Time and Space complexity:"**
   - STL sort(): O(n log n), O(log n)
   - Dutch Flag: O(n), O(1)

4. **"Let me do a quick dry run:"**
   - [Show 2-3 steps with example]

5. **"Let me code this..."**

---

## 🏋️ MUSCLE MEMORY DRILLS

### **Drill 1: Write Blind (5 min)**
Close eyes, write from memory:
- STL sort() ascending/descending
- Dutch Flag algorithm
- Merge sorted arrays

### **Drill 2: Real-World Recognition (3 min)**
See real example → Identify pattern:
- E-commerce filters → ?
- Traffic lights → ?
- Leaderboard → ?

### **Drill 3: Dry Run Speed (10 min)**
Pick any problem, dry run in 2 minutes:
- Dutch Flag with [0,1,2,0,1]
- Merge [1,3,5] and [2,4,6]

---

## 🧠 MEMORY HOOKS (Real-World Analogies)

### 📱 **Phone Contacts** = Basic Sort
- Contacts A-Z = Ascending sort
- "sort(contacts.begin(), contacts.end())"

### 🚦 **Traffic Lights** = Dutch Flag
- Red(0) → Yellow(1) → Green(2)
- All red lights first, then yellow, then green!

### 🛒 **E-commerce** = Custom Comparator
- Sort by price, rating, popularity
- "Sort by user preference!"

### 📧 **Email Merging** = Merge Sorted
- Two inboxes → One unified timeline
- Compare timestamps, pick earlier!

### 🏆 **Leaderboard** = Kth Largest
- 1st, 2nd, 3rd place
- Sort descending, access by index!

### 📚 **Library Books** = Why Sort?
- Sorted by author → Quick binary search!
- Unsorted → Slow linear search!

---

## ⚡ GOLDEN RULES (Commit to Memory!)

```
1. ALWAYS use sort() unless asked for specific algorithm
2. Dutch Flag (0,1,2) - MOST FAMOUS! Know by heart!
3. Custom comparator? Use lambda!
4. Merging sorted? Two pointer!
5. Kth largest? Sort descending + arr[k-1]
6. After sorting → Binary Search becomes possible!
7. Explain with real-world examples in interviews!
```

---

## 🗓️ 5-DAY MASTERY PATH

**Day 1**: Basic sort + Real examples (E-commerce, contacts)  
**Day 2**: Dutch Flag (0,1,2) - Practice 10 times! ⭐  
**Day 3**: Custom comparator (Length, frequency, pairs)  
**Day 4**: Merge sorted arrays (Contact lists, logs)  
**Day 5**: Kth largest + All problems + Mock interview

---

## 📌 PRE-INTERVIEW CHECKLIST (15 min before!)

- [ ] Can write sort() ascending/descending blind
- [ ] Can write Dutch Flag algorithm blind ⭐
- [ ] Can write lambda comparator
- [ ] Can merge two sorted arrays
- [ ] Know Kth largest formula: arr[k-1]
- [ ] Can connect each pattern to real-world example
- [ ] Remember: "STL sort() = IntroSort = O(n log n)"

---

## 📋 ONE-PAGE ASCII PRINTABLE

```
╔════════════════════════════════════════════════════════╗
║          SORTING - WALLET CARD (WITH REAL EXAMPLES)    ║
╠════════════════════════════════════════════════════════╣
║ GOLDEN RULE: ALWAYS use sort() in interviews!         ║
╠════════════════════════════════════════════════════════╣
║ TEMPLATE 1: Basic Sort                                 ║
║   sort(arr.begin(), arr.end());         // Ascending   ║
║   sort(arr.begin(), arr.end(), greater<int>());  // ↓  ║
║   Real: 🛒 E-commerce product filters                  ║
║                                                        ║
║ TEMPLATE 2: Dutch Flag (0,1,2) ⭐ MOST FAMOUS         ║
║   low=0, mid=0, high=n-1;                             ║
║   while(mid<=high) {                                  ║
║     if(arr[mid]==0) swap(arr[low++], arr[mid++]);    ║
║     else if(arr[mid]==1) mid++;                       ║
║     else swap(arr[mid], arr[high--]);                 ║
║   }                                                    ║
║   Real: 🚦 Sort traffic lights (Red→Yellow→Green)     ║
║                                                        ║
║ TEMPLATE 3: Custom Comparator                         ║
║   sort(arr.begin(), arr.end(), [](auto a, auto b) {  ║
║     return a.length() < b.length();                   ║
║   });                                                  ║
║   Real: 📏 Word game (short words first)              ║
║                                                        ║
║ TEMPLATE 4: Merge Sorted                              ║
║   while(i<n && j<m) {                                 ║
║     if(a[i]<=b[j]) result.push(a[i++]);              ║
║     else result.push(b[j++]);                         ║
║   }                                                    ║
║   Real: 📱 Merge two contact lists                    ║
║                                                        ║
║ TEMPLATE 5: Kth Largest                               ║
║   sort(arr.begin(), arr.end(), greater<int>());       ║
║   return arr[k-1];                                    ║
║   Real: 🏆 Leaderboard - 3rd place winner            ║
╠════════════════════════════════════════════════════════╣
║ COMPLEXITY:                                            ║
║   STL sort(): O(n log n), O(log n)                    ║
║   Dutch Flag: O(n), O(1) ⭐                           ║
║   Merge: O(n+m), O(n+m)                               ║
║   Kth Largest: O(n log n), O(1)                       ║
╠════════════════════════════════════════════════════════╣
║ MANTRAS:                                               ║
║   "sort() = IntroSort = O(n log n)!"                  ║
║   "Dutch Flag: 0→left, 2→right, 1→stay!" ⭐           ║
║   "Custom order = Lambda!"                             ║
║   "Merge sorted = Two pointers!"                       ║
║   "Kth largest = arr[k-1] after sort!"                ║
╠════════════════════════════════════════════════════════╣
║ REAL-WORLD CONNECTIONS:                                ║
║   📱 Phone contacts = Basic sort A-Z                  ║
║   🚦 Traffic lights = Dutch Flag (R,Y,G)              ║
║   🛒 E-commerce = Sort by price                       ║
║   🏆 Leaderboard = Kth largest                        ║
║   📧 Email merge = Merge sorted                       ║
║   📏 Word game = Custom comparator                    ║
╠════════════════════════════════════════════════════════╣
║ INTERVIEW CHECKLIST:                                   ║
║   ✓ Identify pattern (Basic, Dutch, Custom, etc.)    ║
║   ✓ Connect to real-world example                     ║
║   ✓ Explain approach before coding                    ║
║   ✓ State time/space complexity                       ║
║   ✓ Dry run with small example                        ║
╚════════════════════════════════════════════════════════╝
```

---

## 🚀 FINAL POWER TIPS

1. **Explain with real examples** - "Like sorting Amazon products..."
2. **Dutch Flag (0,1,2)** - 85-95% probability in interviews! ⭐
3. **STL sort()** - Interview-friendly, optimized, reliable
4. **After sorting** - Many optimizations become possible!
5. **Practice blind** - Write templates without looking

---

## 🌍 WHY REAL-WORLD EXAMPLES MATTER?

```
Interviewer appreciates when you say:
✅ "This is like sorting Amazon products by price..."
✅ "Similar to organizing traffic light signals..."
✅ "Like merging two contact lists from different phones..."

❌ Don't just say: "I'll sort the array"
✅ Say: "I'll sort like arranging phone contacts A-Z"

Shows: Practical thinking + Communication skills!
```

---

**Remember: Sorting is everywhere in real life!**  
**Master these 5 patterns → 85-95% of sorting problems solved! 💪🎯**

---

*Print this page and keep it in your wallet for last-minute revision before interviews!* 📄✨

