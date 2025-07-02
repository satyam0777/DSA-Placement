// stock span problem
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;



// Method :Concept taught by Aditya Verma
// This is the same logic as nearest greater to left 
// consective smalleror equal to before it == nearest smaller to left
vector<int> v;
stack<pair<int, int>> s;
void stockSpan(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        // Check if stack is empty then push -1 in vector
        if (s.empty()) {
            v.push_back(1);
        } else if (!s.empty() && s.top().first < arr[i]) {  //s.top().first < arr[i] means the top of the stack is smaller than the current element and s.top().second is the index of the top element
            // If the top of the stack is smaller than the current element, calculate span
            v.push_back(i - s.top().second);
        } else if (!s.empty() && s.top().first >= arr[i]) {
            // Pop elements from the stack until we find a smaller element
            while (!s.empty() && s.top().first >= arr[i]) {
                s.pop();
            }
            // If stack is not empty, calculate span
            if (!s.empty()) {
                v.push_back(i - s.top().second);
            } else {
                v.push_back(i + 1); // If stack is empty, span is i + 1
            }
        }
        // Push the current element onto the stack with its index
        s.push({arr[i], i});   //s.first is the value and s.second is the index
    }
}
// if you have any doubt then please watch the video of Aditya Verma stock span problem on youtube 
// he explain it very well and easy to understand 