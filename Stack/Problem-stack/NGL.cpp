//nearest greater to left
#include<bits/stdc++.h>
#include <iostream>
#include <vector>   
#include <stack>
using namespace std;

vector<int> nearestGreaterToLeft(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize result with -1
    stack<int> s; // Stack to keep track of indices

    for (int i = 0; i < n; ++i) {
        // Pop elements from the stack until we find a greater element
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        // If stack is not empty, the top element is the nearest greater to the left
        if (!s.empty()) {
            result[i] = arr[s.top()];
        }
        // Push current index onto the stack
        s.push(i);
    }

    return result;
}

// method 2: concept teach by Aditya Verma (it easy to understand so recommended to watch video)
// this is the same logic as nearest greater to right but we go from left to right
// and we don't need to reverse the vector at the end
// because we are already going from left to right
// and the order of elements is maintained as we process from left to right
vector<int> v; 
stack<int> s;
void nearestGreaterToLeft(int arr[], int n) {
    for (int i = 0; i < n; i++) {     // Iterate from left to right 
        // Check if stack is empty then push -1 in vector 
        if (s.empty()) {
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
    // No need to reverse the vector as we are going from left to right
    // The order of elements is maintained as we process from left to right
}