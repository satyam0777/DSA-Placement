//nearest smaller to right

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nearestSmallerToRight(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize result with -1
    stack<int> s; // Stack to keep track of indices

    for (int i = n - 1; i >= 0; --i) {
        // Pop elements from the stack until we find a smaller element
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        // If stack is not empty, the top element is the nearest smaller to the right
        if (!s.empty()) {
            result[i] = arr[s.top()];
        }
        // Push current index onto the stack
        s.push(i);
    }

    return result;
}

// method 2*: concept teach by Aditya Verma (it easy to understand so recommended to watch video)
// This is the same logic as nearest smaller to left but we go from right to left
// and we need to reverse the vector at the end
vector<int> v;
stack<int> s;

void nearestSmallerToRight(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        // Check if stack is empty then push -1 in vector
        if (s.empty()) {
            v.push_back(-1);
        } else if (!s.empty() && s.top() < arr[i]) { // here we check s.top() < arr[i] bcoz we want to find the nearest smaller element to the right
            // If the top of the stack is smaller than the current element, push it to vector
            v.push_back(s.top());
        } else if (!s.empty() && s.top() >= arr[i]) { //pop greater or equal elements bcoz we want smaller element thats why we check s.top() >= arr[i]
            // Pop elements from the stack until we find a smaller element
            while (!s.empty() && s.top() >= arr[i]) {
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
    // Reverse the vector to maintain the original order
    reverse(v.begin(), v.end());
}