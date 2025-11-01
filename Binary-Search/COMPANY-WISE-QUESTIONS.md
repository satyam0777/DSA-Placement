# Binary Search - Company-Wise Questions & Interview Patterns

---

## 🏢 SERVICE-BASED COMPANIES (<10 LPA)

### **Company Difficulty Mapping**

| Company | Difficulty Level | Focus Area | Rounds |
|---------|------------------|------------|--------|
| TCS | Easy to Medium | Basic BS, Rotated Array | 2-3 |
| Wipro | Easy to Medium | Classic BS, First/Last | 2-3 |
| Infosys | Easy | Very Basic BS | 2 |
| Cognizant | Easy to Medium | BS on Answer | 2-3 |
| Capgemini | Easy | Classic patterns | 2 |
| Accenture | Easy | Fundamental BS | 2 |
| HCL | Easy to Medium | Standard problems | 2-3 |
| Tech Mahindra | Medium | Mixed patterns | 3 |

---

## 📋 COMPANY-WISE FREQUENTLY ASKED QUESTIONS

### **TCS (Tata Consultancy Services)**

**Interview Pattern:**
- 1 Coding Round (Online)
- 1-2 Technical Interviews
- Focus: Problem-solving approach > Perfect code

**Most Asked BS Questions:**

1. **Search in a Sorted Array** ⭐⭐⭐⭐⭐
   - Difficulty: Easy
   - What they check: Basic understanding
   ```
   "Can you find if element X exists in this sorted array?"
   ```

2. **Search in Rotated Sorted Array** ⭐⭐⭐⭐⭐
   - Difficulty: Medium
   - What they check: Pattern recognition
   ```
   "Array was sorted, then rotated. Find the target."
   ```

3. **Count Occurrences** ⭐⭐⭐⭐
   - Difficulty: Easy-Medium
   - What they check: Modified BS
   ```
   "Find how many times X appears in sorted array with duplicates."
   ```

4. **Find Floor and Ceil** ⭐⭐⭐
   - Difficulty: Medium
   - What they check: Boundary handling
   ```
   "Find largest element ≤ X and smallest element ≥ X"
   ```

**TCS Interview Tip:**
> They love to ask follow-up questions like "What if duplicates exist?" 
> or "Can you optimize further?" Be prepared to explain variations.

---

### **Wipro**

**Interview Pattern:**
- 1 Online Assessment
- 2 Technical Interviews
- Focus: Code quality + Explanation

**Most Asked BS Questions:**

1. **First and Last Position** ⭐⭐⭐⭐⭐
   - Difficulty: Medium
   - Classic LeetCode 34
   ```
   "Find first and last position of target in sorted array"
   ```

2. **Square Root** ⭐⭐⭐⭐⭐
   - Difficulty: Medium
   - Without using sqrt()
   ```
   "Find floor of square root without built-in function"
   ```

3. **Search Insert Position** ⭐⭐⭐⭐
   - Difficulty: Easy
   - Lower bound concept
   ```
   "Where should target be inserted to maintain sorted order?"
   ```

4. **Peak Element** ⭐⭐⭐⭐
   - Difficulty: Medium
   ```
   "Find any element that is greater than its neighbors"
   ```

**Wipro Interview Tip:**
> They test edge cases thoroughly. Always mention and handle:
> - Empty array
> - Single element
> - All elements same
> - Target not present

---

### **Infosys**

**Interview Pattern:**
- 1 Online Test (HackWithInfy for better package)
- 1-2 Technical Interviews
- Focus: Very basics + Communication

**Most Asked BS Questions:**

1. **Classic Binary Search** ⭐⭐⭐⭐⭐
   - Difficulty: Easy
   - Pure fundamentals
   ```
   "Implement binary search to find an element"
   ```

2. **Find Minimum in Rotated Array** ⭐⭐⭐⭐
   - Difficulty: Medium
   ```
   "Find minimum element in rotated sorted array"
   ```

3. **Count of Element** ⭐⭐⭐
   - Difficulty: Easy
   ```
   "Count occurrences of X in sorted array"
   ```

**Infosys Interview Tip:**
> Keep it simple. They prefer clear explanation over complex optimization.
> Speak slowly and clearly. Show your working on paper/whiteboard.

---

### **Cognizant**

**Interview Pattern:**
- 1 Online Assessment (Automata)
- 2-3 Technical Interviews
- Focus: BS on Answer problems

**Most Asked BS Questions:**

1. **Aggressive Cows** ⭐⭐⭐⭐⭐
   - Difficulty: Medium-Hard
   - BS on Answer
   ```
   "Place cows in stalls such that minimum distance is maximized"
   ```

2. **Book Allocation** ⭐⭐⭐⭐
   - Difficulty: Medium
   - BS on Answer
   ```
   "Allocate books to students to minimize maximum pages"
   ```

3. **Capacity to Ship Packages** ⭐⭐⭐⭐
   - Difficulty: Medium
   - BS on Answer
   ```
   "Find minimum ship capacity to deliver within D days"
   ```

4. **Koko Eating Bananas** ⭐⭐⭐
   - Difficulty: Medium
   - BS on Answer
   ```
   "Find minimum eating speed to finish all bananas in H hours"
   ```

**Cognizant Interview Tip:**
> Focus on BS on Answer pattern. Practice explaining:
> 1. How you define search space
> 2. What condition to check
> 3. How to update low/high

---

### **Capgemini**

**Interview Pattern:**
- 1 Online Test
- 1-2 Technical Interviews
- Focus: Standard problems + Pseudocode

**Most Asked BS Questions:**

1. **Search in Sorted Array** ⭐⭐⭐⭐⭐
   - Difficulty: Easy
   ```
   "Write binary search from scratch"
   ```

2. **Find First Occurrence** ⭐⭐⭐⭐
   - Difficulty: Medium
   ```
   "Find first occurrence of target in array with duplicates"
   ```

3. **Peak Element** ⭐⭐⭐
   - Difficulty: Medium
   ```
   "Find peak in array where arr[i] > arr[i-1] and arr[i] > arr[i+1]"
   ```

**Capgemini Interview Tip:**
> They may ask you to write pseudocode first. Practice explaining logic 
> in plain English before coding.

---

### **Accenture**

**Interview Pattern:**
- 1 Online Test (Cocubes)
- 1-2 Technical + HR
- Focus: Very basics

**Most Asked BS Questions:**

1. **Classic Binary Search** ⭐⭐⭐⭐⭐
   - Difficulty: Easy
   ```
   "Implement binary search"
   ```

2. **Linear vs Binary Search Comparison** ⭐⭐⭐⭐
   - Difficulty: Conceptual
   ```
   "Explain when to use binary vs linear search"
   ```

3. **Simple Finding Problems** ⭐⭐⭐
   - Difficulty: Easy
   ```
   "Find if X exists in sorted array"
   ```

**Accenture Interview Tip:**
> Focus more on explaining concepts than complex problems.
> They test communication skills heavily.

---

## 📊 DIFFICULTY DISTRIBUTION FOR SERVICE-BASED

```
Easy (60%):
- Classic binary search
- Search insert position
- Count occurrences
- Find element in array

Medium (35%):
- First/Last occurrence
- Rotated sorted array
- Square root
- Peak element
- BS on Answer (basic)

Hard (5%):
- Aggressive Cows
- Painter's Partition
- Complex BS on Answer
```

---

## 🎯 MUST-PREPARE BASED ON COMPANY

### **If Targeting TCS/Wipro/HCL:**
**Top 5 Priority:**
1. Classic Binary Search
2. First and Last Position
3. Search in Rotated Sorted Array
4. Count Occurrences
5. Square Root

### **If Targeting Infosys/Accenture/Capgemini:**
**Top 5 Priority:**
1. Classic Binary Search
2. Search Insert Position
3. Find Minimum in Rotated Array
4. Basic First Occurrence
5. Peak Element

### **If Targeting Cognizant/Tech Mahindra:**
**Top 5 Priority:**
1. Classic Binary Search
2. BS on Answer (Ship Capacity, Book Allocation)
3. Search in Rotated Array
4. Aggressive Cows (if time permits)
5. First and Last Position

---

## 💼 ACTUAL INTERVIEW SCENARIOS

### **Scenario 1: TCS Interview (Candidate: Satyam, Role: Developer)**

**Question:** "You have a sorted array with duplicates. Find the first and last position of a target element."

**Expected Flow:**
```
Candidate: "I'll use binary search twice - once for first occurrence 
           and once for last occurrence."
           
Interviewer: "Why not just linear search?"

Candidate: "Linear search is O(n). Binary search gives O(log n). 
           Since array is sorted, we should leverage that property."
           
Interviewer: "Good. Show me the code."

[Candidate codes first occurrence]

Interviewer: "What if target doesn't exist?"

Candidate: "I return -1 in both cases, so output would be [-1, -1]."

✅ SELECTED
```

---

### **Scenario 2: Wipro Interview (Candidate: Satyam, Role: SE)**

**Question:** "Find square root without using sqrt() function."

**Expected Flow:**
```
Candidate: "Can I clarify - do you want the floor value?"

Interviewer: "Yes, floor value only."

Candidate: "This is a binary search on answer problem. My search space 
           is from 1 to x. For each mid, I'll check if mid*mid <= x."
           
Interviewer: "What about overflow?"

Candidate: "I'll use long long for the multiplication to prevent overflow."

Interviewer: "Good thinking. Proceed."

✅ SELECTED
```

---

### **Scenario 3: Infosys Interview (Candidate: Amit, Role: Systems Engineer)**

**Question:** "Implement binary search."

**Expected Flow:**
```
Candidate: "I'll use two pointers approach. Low starts at 0, high at n-1.
           In each iteration, I calculate mid and compare with target."
           
[Candidate writes clean code]

Interviewer: "Why did you use low + (high - low) / 2?"

Candidate: "To prevent integer overflow that could occur with (low + high) / 2."

Interviewer: "Very good. What's the time complexity?"

Candidate: "O(log n) because we halve the search space each time."

✅ SELECTED
```

---

**Quote:**
> "They didn't ask anything beyond rotated array. Basic BS mastery + 
> good communication = offer letter."

---

## 📈 PREPARATION TIMELINE

### **If You Have 1 Week:**
- Day 1-2: Classic BS, First/Last Occurrence (5 problems)
- Day 3-4: Rotated Array, Peak Element (3 problems)
- Day 5: Square Root, BS on Answer basics (2 problems)
- Day 6: Revise all, practice without looking (10 problems)
- Day 7: Mock interview with friend

---

## 🎯 FINAL REALITY CHECK

**What Service-Based Companies ACTUALLY Test:**

✅ **Do you understand the basics?**  
✅ **Can you communicate your approach?**  
✅ **Do you write clean code?**  
✅ **Can you handle edge cases?**  
✅ **Are you confident but humble?**  

❌ **Can you solve Codeforces Div1 problems?** (NO!)  
❌ **Do you know every BS variation?** (NO!)  
❌ **Can you solve in 5 minutes?** (NO!)  

---

## 💡 COMPANY-SPECIFIC TIPS SUMMARY

| Company | What They Value Most |
|---------|---------------------|
| **TCS** | Problem-solving approach, variations |
| **Wipro** | Code quality, edge cases |
| **Infosys** | Clear communication, basics |
| **Cognizant** | BS on Answer, helper functions |
| **Capgemini** | Pseudocode, step-by-step thinking |
| **Accenture** | Conceptual clarity, comparison |

---

## 🔥 LAST WORDS

**For Service-Based Companies (<10 LPA):**

1. **You don't need to know 100 BS problems**
   - Master 10-15 core problems
   - Understand patterns deeply

2. **Communication > Code**
   - Explain your thinking
   - Draw diagrams
   - Do dry runs

3. **Consistency > Brilliance**
   - Solve same problems 3 times
   - Build muscle memory
   - Gain confidence

4. **Basics > Advanced**
   - Perfect classic BS first
   - Then first/last occurrence
   - Finally BS on Answer

---

**Remember:** 
> "In service-based companies, the candidate who explains well 
> gets selected over the one who codes silently but correctly."

---

**Your Goal:** Not to impress, but to show clarity.


**Your Strategy:** Master templates, practice explaining, stay confident.

---

**You're going to nail this! **

Good luck with your placement! 🎉
