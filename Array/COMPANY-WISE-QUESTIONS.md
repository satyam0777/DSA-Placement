# Array - Company-Wise Questions & Interview Patterns

---

## 🏢 SERVICE-BASED COMPANIES (<10 LPA)

### **Company Difficulty Mapping**

| Company | Array Focus | Difficulty | Common Patterns |
|---------|-------------|------------|-----------------|
| **TCS** | Very High (75%) | Easy-Medium | Two Pointer, Kadane's, Hashing |
| **Wipro** | High (70%) | Easy-Medium | Sliding Window, Prefix Sum |
| **Infosys** | Very High (80%) | Easy | Basic operations, Two Pointer |
| **Cognizant** | High (65%) | Medium | Kadane's, Hashing, Sliding Window |
| **Capgemini** | High (70%) | Easy-Medium | Two Pointer, Basic patterns |
| **Accenture** | Very High (75%) | Easy | Simple operations, Frequency |
| **HCL** | High (68%) | Easy-Medium | Mixed patterns |
| **Tech Mahindra** | Medium (60%) | Medium | All patterns |

---

## 📋 COMPANY-WISE FREQUENTLY ASKED QUESTIONS

### **TCS (Tata Consultancy Services)**

**Interview Pattern:**
- 1-2 Coding Rounds (Online + Technical)
- Heavy focus on arrays (75% problems)
- Expect 2-3 array questions per interview

**Most Asked Array Questions:**

#### **1. Two Sum** ⭐⭐⭐⭐⭐
- **Difficulty:** Easy
- **Pattern:** Hashing
- **Frequency:** Asked in 80% of TCS interviews
```
"Given an array, find two numbers that add up to target."
```

**What they check:**
- Can you think of hashmap optimization?
- Do you handle edge cases?
- Can you explain time/space tradeoff?

---

#### **2. Maximum Subarray Sum (Kadane's)** ⭐⭐⭐⭐⭐
- **Difficulty:** Medium  
- **Pattern:** Kadane's Algorithm
- **Frequency:** Very High
```
"Find the contiguous subarray with maximum sum."
```

**Follow-up questions they ask:**
- "Can you print the subarray indices?"
- "What if all elements are negative?"
- "Can you do it in O(1) space?"

---

#### **3. Rotate Array** ⭐⭐⭐⭐⭐
- **Difficulty:** Easy-Medium
- **Pattern:** Reversal
- **Frequency:** High
```
"Rotate array to right by k positions."
```

**TCS variant:**
> "Rotate array left by k positions" (same logic, adjust k)

---

#### **4. Remove Duplicates from Sorted Array** ⭐⭐⭐⭐⭐
- **Difficulty:** Easy
- **Pattern:** Two Pointer
- **Frequency:** Very High
```
"Remove duplicates in-place, return new length."
```

**What they expect:**
> "I'll use two pointers - one slow for unique elements, one fast to explore."

---

#### **5. Leaders in Array** ⭐⭐⭐⭐
- **Difficulty:** Easy
- **Pattern:** Traverse from right
- **Frequency:** Medium-High
```
"Find all elements greater than all elements to their right."
```

**TCS loves this:** Very common in TCS NQT and Digital rounds!

---

#### **6. Stock Buy/Sell** ⭐⭐⭐⭐⭐
- **Difficulty:** Easy
- **Pattern:** Single pass
- **Frequency:** High
```
"Find maximum profit from one buy-sell transaction."
```

---

#### **7. Subarray Sum Equals K** ⭐⭐⭐⭐
- **Difficulty:** Medium
- **Pattern:** Prefix Sum + Hashing
- **Asked in:** TCS Digital (higher package)
```
"Count subarrays with sum equal to k."
```

---

### **TCS Interview Tip:**
> They test your **thought process** more than perfect code.
> Always explain: "I can do brute force O(n²), but optimizing with [pattern] gives O(n)."
> TCS interviewers LOVE when you compare approaches!

---

### **Wipro**

**Interview Pattern:**
- 2 Technical Rounds
- Coding + Theory mix
- Arrays in 70% of coding questions

**Most Asked Array Questions:**

#### **1. Maximum Sum Subarray of Size K** ⭐⭐⭐⭐⭐
- **Pattern:** Sliding Window
- **Difficulty:** Easy
```
"Find maximum sum of any k consecutive elements."
```

**Wipro loves:** Sliding window problems!

---

#### **2. Longest Substring Without Repeating** ⭐⭐⭐⭐⭐
- **Pattern:** Sliding Window + Hashing
- **Difficulty:** Medium
```
"Find length of longest substring with unique characters."
```

**What they ask:**
> "Can you do it in one pass? What's the space complexity?"

---

#### **3. Move Zeros** ⭐⭐⭐⭐⭐
- **Pattern:** Two Pointer
- **Difficulty:** Easy
```
"Move all zeros to end, maintain order of non-zeros."
```

**Wipro variant:**
> "Move all zeros to beginning" (same logic, reverse)

---

#### **4. Find Missing Number** ⭐⭐⭐⭐⭐
- **Pattern:** Math / XOR
- **Difficulty:** Easy
```
"Array has n-1 numbers from 0 to n. Find missing."
```

**They expect two solutions:**
1. Sum formula approach
2. XOR approach (bonus points!)

---

#### **5. Contains Duplicate** ⭐⭐⭐⭐
- **Pattern:** Hashing
- **Difficulty:** Easy
```
"Check if array has any duplicates."
```

---

#### **6. Prefix Sum for Range Queries** ⭐⭐⭐⭐
- **Pattern:** Prefix Sum
- **Difficulty:** Medium
```
"Given multiple range sum queries, answer efficiently."
```

**Wipro loves:** Optimization questions!

---

### **Wipro Interview Tip:**
> Focus on **edge cases** heavily. They WILL ask:
> - "What if array is empty?"
> - "What if k > array size?"
> - "What if all elements are same?"
> 
> Handle proactively for bonus points!

---

### **Infosys**

**Interview Pattern:**
- 1-2 Technical Rounds
- Very basic to easy level
- Arrays in 80% of questions

**Most Asked Array Questions:**

#### **1. Reverse an Array** ⭐⭐⭐⭐⭐
- **Difficulty:** Very Easy
- **Pattern:** Two Pointer
```
"Reverse array in-place."
```

**Infosys level:** They test basics!

---

#### **2. Find Max and Min** ⭐⭐⭐⭐⭐
- **Difficulty:** Very Easy
- **Pattern:** Single pass
```
"Find maximum and minimum element in array."
```

---

#### **3. Linear Search** ⭐⭐⭐⭐
- **Difficulty:** Very Easy
```
"Search for element in array."
```

---

#### **4. Count Frequency** ⭐⭐⭐⭐⭐
- **Pattern:** Hashing
- **Difficulty:** Easy
```
"Count frequency of each element."
```

---

#### **5. Sum of Elements** ⭐⭐⭐⭐
- **Difficulty:** Very Easy
```
"Find sum of all array elements."
```

---

#### **6. Check if Sorted** ⭐⭐⭐⭐
- **Difficulty:** Easy
```
"Check if array is sorted in ascending order."
```

---

#### **7. Remove Duplicates** ⭐⭐⭐⭐
- **Pattern:** Hashing or Two Pointer
- **Difficulty:** Easy
```
"Remove duplicates from array."
```

---

### **Infosys Interview Tip:**
> Focus on **clear communication**. They value:
> - Step-by-step explanation
> - Clean, readable code
> - Basic complexity analysis
> 
> Don't overthink! They ask straightforward questions.

---

### **Cognizant**

**Interview Pattern:**
- 2-3 Technical Rounds
- Medium difficulty
- Theory + Coding mix

**Most Asked Array Questions:**

#### **1. Kadane's Algorithm Variations** ⭐⭐⭐⭐⭐
- **Difficulty:** Medium
```
"Maximum subarray sum"
"Maximum circular subarray sum"
"Maximum product subarray"
```

**Cognizant loves:** Kadane's and its variations!

---

#### **2. Subarray Sum Problems** ⭐⭐⭐⭐⭐
- **Pattern:** Prefix Sum + Hashing
- **Difficulty:** Medium
```
"Subarray sum equals K"
"Count subarrays with given sum"
```

---

#### **3. Sliding Window Problems** ⭐⭐⭐⭐
- **Pattern:** Sliding Window
- **Difficulty:** Medium
```
"Longest subarray with at most K distinct elements"
"Minimum window substring"
```

---

#### **4. Two Sum Variations** ⭐⭐⭐⭐⭐
- **Pattern:** Hashing / Two Pointer
```
"Two sum"
"Three sum"
"Closest sum to target"
```

---

#### **5. Sort Colors (Dutch Flag)** ⭐⭐⭐⭐
- **Pattern:** Three Pointer
- **Difficulty:** Medium
```
"Sort array of 0s, 1s, and 2s."
```

---

### **Cognizant Interview Tip:**
> They ask **variations** of standard problems.
> Master the base problem, then handle variations.
> Example: Know Two Sum → Easily solve Three Sum, Four Sum.

---

### **Capgemini**

**Interview Pattern:**
- 1-2 Rounds
- Focus on pattern recognition
- Code + Explanation

**Most Asked Array Questions:**

#### **1. Find Pair with Given Sum** ⭐⭐⭐⭐⭐
- **Pattern:** Two Pointer / Hashing
- **Difficulty:** Easy
```
"Find if pair with sum X exists."
```

---

#### **2. Rotate Array** ⭐⭐⭐⭐
- **Pattern:** Reversal
- **Difficulty:** Easy-Medium
```
"Rotate by K positions."
```

---

#### **3. Maximum and Minimum** ⭐⭐⭐⭐
- **Difficulty:** Easy
```
"Find max and min in one traversal."
```

---

#### **4. Kadane's Algorithm** ⭐⭐⭐⭐
- **Difficulty:** Medium
```
"Maximum subarray sum."
```

---

#### **5. Merge Two Sorted Arrays** ⭐⭐⭐⭐
- **Pattern:** Two Pointer
- **Difficulty:** Easy
```
"Merge without extra space."
```

---

### **Capgemini Interview Tip:**
> They often ask you to **write pseudocode first**.
> Practice explaining logic in plain English before coding.

---

### **Accenture**

**Interview Pattern:**
- 1-2 Simple Rounds
- Very basic problems
- Focus on fundamentals

**Most Asked Array Questions:**

#### **1. Sum of Array** ⭐⭐⭐⭐⭐
- **Difficulty:** Very Easy
```
"Calculate sum of all elements."
```

---

#### **2. Find Duplicates** ⭐⭐⭐⭐⭐
- **Pattern:** Hashing
- **Difficulty:** Easy
```
"Find duplicate elements."
```

---

#### **3. Reverse Array** ⭐⭐⭐⭐
- **Difficulty:** Very Easy
```
"Reverse array in-place."
```

---

#### **4. Second Largest** ⭐⭐⭐⭐
- **Difficulty:** Easy
```
"Find second largest element."
```

---

#### **5. Count Even/Odd** ⭐⭐⭐⭐
- **Difficulty:** Very Easy
```
"Count even and odd numbers."
```

---

### **Accenture Interview Tip:**
> Focus on **concepts**, not complex algorithms.
> They test understanding more than coding skills.
> Explain clearly, write clean code.

---

## 🚀 SUCCESS STORIES & REAL SCENARIOS

### **Success Story 1: TCS Digital (7 LPA)**
**Background:** Tier 2 college, 7.5 CGPA

**Interview Experience:**
```
Round 1: Two Sum, Kadane's Algorithm
Round 2: Leaders in Array, Rotate Array

Key: "I explained brute force first, then optimized.
     Drew diagrams for Kadane's. Got offer!"
```

**What Worked:**
✅ Clear communication  
✅ Comparing approaches  
✅ Drawing examples  

---

### **Success Story 2: Wipro (3.5 LPA)**
**Background:** Non-CS background

**Interview Experience:**
```
Round 1: Move Zeros, Contains Duplicate
Round 2: Maximum sum subarray size K

Key: "I mentioned edge cases before they asked.
     Used sliding window perfectly. Selected!"
```

**What Worked:**
✅ Proactive edge case handling  
✅ Pattern recognition  
✅ Clean code  

---

### **Success Story 3: Infosys (3.6 LPA)**
**Background:** Tier 3 college

**Interview Experience:**
```
Round 1: Find max/min, Reverse array
Round 2: Count frequency, Remove duplicates

Key: "Questions were basic. I explained clearly
     and wrote clean code. That's all they wanted!"
```

**What Worked:**
✅ Clear explanation  
✅ Simple solutions  
✅ Confidence  


---

## 🎯 MUST-PREPARE BASED ON COMPANY

### **Targeting TCS/Wipro/HCL:**
**Priority Order:**
1. Two Sum ⭐⭐⭐⭐⭐
2. Kadane's Algorithm ⭐⭐⭐⭐⭐
3. Two Pointer problems ⭐⭐⭐⭐⭐
4. Sliding Window basics ⭐⭐⭐⭐
5. Hashing problems ⭐⭐⭐⭐

### **Targeting Infosys/Accenture/Capgemini:**
**Priority Order:**
1. Basic operations (reverse, max/min) ⭐⭐⭐⭐⭐
2. Two Pointer (remove duplicates) ⭐⭐⭐⭐⭐
3. Frequency counting ⭐⭐⭐⭐
4. Simple Kadane's ⭐⭐⭐⭐
5. Two Sum ⭐⭐⭐⭐

### **Targeting Cognizant/Tech Mahindra:**
**Priority Order:**
1. Kadane's + variations ⭐⭐⭐⭐⭐
2. Prefix Sum + Hashing ⭐⭐⭐⭐⭐
3. Sliding Window (all types) ⭐⭐⭐⭐⭐
4. Two/Three Sum ⭐⭐⭐⭐
5. Sort Colors ⭐⭐⭐⭐

---

## 💡 COMPANY-SPECIFIC TIPS SUMMARY

| Company | What They Value Most | Preparation Focus |
|---------|---------------------|-------------------|
| **TCS** | Thought process, comparisons | Explain brute force → optimized |
| **Wipro** | Edge cases, optimization | Handle edge cases proactively |
| **Infosys** | Clear communication | Simple, clean solutions |
| **Cognizant** | Problem variations | Master base + variations |
| **Capgemini** | Pattern recognition | Pseudocode → Code |
| **Accenture** | Conceptual clarity | Explain concepts well |



---



## 📊 ACTUAL INTERVIEW SCENARIOS

### **Scenario 1: TCS Interview**

**Interviewer:** "Find two numbers that add up to target."

**You:** 
> "The array is unsorted? Okay. Brute force would be nested loops O(n²),
> checking all pairs. But I can optimize using hashmap to O(n).
>
> My approach: For each element, I check if (target - element) exists 
> in hashmap. If yes, found the pair. If no, add current element.
>
> Let me code... [write solution]
>
> Edge cases: no solution returns empty, handles negatives.
> Time: O(n), Space: O(n) for hashmap."

**Result:** ✅ SELECTED

---

### **Scenario 2: Infosys Interview**

**Interviewer:** "Remove duplicates from sorted array."

**You:**
> "Since array is sorted, duplicates will be together. 
> I'll use two pointers - slow pointer tracks unique elements position,
> fast pointer explores the array.
>
> When fast pointer finds new unique element, I move it to slow pointer's
> next position and increment slow.
>
> [Dry run with example on paper]
>
> Time: O(n), Space: O(1) as we modify in-place."

**Result:** ✅ SELECTED

---

## 🌟 CLOSING MOTIVATION

**Remember:**

- **Arrays = 70% of service-based interviews**
- **6 patterns solve 90% of problems**
- **Communication > Perfect code**
- **You're well-prepared!**


---

**Good luck with your placement!** 🎉

*P.S. Remember to stay calm, explain clearly, and trust your preparation!*
