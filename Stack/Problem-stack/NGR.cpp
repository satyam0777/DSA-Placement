// nearest greater to right or NGR
// Problem: Given an array of integers, find the nearest greater element to the right for each element.
#include<bits/stdc++.h>
#include <iostream>
#include <vector>   
#include <stack>
using namespace std;
//method 1:
vector<int> nearestGreaterToRight(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize result with -1
    stack<int> s; // Stack to keep track of indices

    for (int i = 0; i < n; ++i) {
        // Pop elements from the stack until we find a greater element
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        // If stack is not empty, the top element is the nearest greater to the right
        if (!s.empty()) {
            result[i] = arr[s.top()];
        }
        // Push current index onto the stack
        s.push(i);
    }

    return result;
}

//method 2: concept teach by Aditya Verma

vector<int> v;
stack<int> s;
void nearestGreaterToRight(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
       //check if stack is empty then push -1 in vector 
       if(s.empty()) {
            v.push_back(-1);
        } else if (!s.empty() && s.top() > arr[i]) {
            // If the top of the stack is greater than the current element, push it to vector
            v.push_back(s.top());
        } else if (!s.empty() && s.top() <= arr[i]) {
            // Pop elements from the stack until we find a greater element
            while (!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
            // If stack is not empty, push the top element to vector
            if (!s.empty()) {
                v.push_back(s.top());
            } else {
                v.push_back(-1);
            }
        }
        // Push the current element onto the stack
        s.push(arr[i]);
    }
    // Reverse the vector to maintain the order of elements
    reverse(v.begin(), v.end());
   
}
// explanation:
/*
🔁 Loop Direction:
We go right to left (for (int i = n - 1; i >= 0; i--)) because we are looking for the nearest greater to the right.

 Full Flow of if-else if:
For each element arr[i] from right to left:

if (s.empty()) {
    v.push_back(-1);
}
👉 If nothing is in the stack, there's no right-side element → so push -1.


else if (!s.empty() && s.top() > arr[i]) {
    v.push_back(s.top());
}
👉 If the top of the stack is greater, it's the nearest greater element to the right → push it.


else if (!s.empty() && s.top() <= arr[i]) {
    while (!s.empty() && s.top() <= arr[i]) {
        s.pop();
    }
    if (!s.empty()) {
        v.push_back(s.top());
    } else {
        v.push_back(-1);
    }
}
👉 If stack top is smaller or equal, we pop until we find a greater one.

If we find a greater one → push it.

Else (stack became empty) → push -1.

🔄 Then, always:

s.push(arr[i]);
Push the current element to stack → it might be useful for the next elements on the left.

🧠 Summary Logic Flow:
Is stack empty? → push -1

Top > current? → push top

Else, pop until you find a greater → push that or -1

🧪 Example:
Let's say arr = [1, 3, 2, 4]
We go from right to left → start with 4

i	arr[i]	stack before	action	vector
3	4	   empty	  push        -1	      [-1]
2	2	4	4 > 2 → push 4	[-1, 4]
1	3	4, 2	2 ≤ 3 → pop 2 → 4 > 3 → push 4	[-1, 4, 4]
0	1	4, 3	3 > 1 → push 3	[-1, 4, 4, 3]

Now reverse vector → [3, 4, 4, -1]

❓ Your Doubt Answered:
Yes, the flow is like:

Check first if → if true, push -1 and go to next element

If false, check else if (stack top > arr[i])

If false again, go to last else if → pop until condition fails

And at the end, push the current element for future comparisons.

*/