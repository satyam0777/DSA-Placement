//nearest smaller to left
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nearestSmallerToLeft(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize result with -1
    stack<int> s; // Stack to keep track of indices

    for (int i = 0; i < n; ++i) {
        // Pop elements from the stack until we find a smaller element
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        // If stack is not empty, the top element is the nearest smaller to the left
        if (!s.empty()) {
            result[i] = arr[s.top()];
        }
        // Push current index onto the stack
        s.push(i);
    }

    return result;
}

// method 2: concept teach by Aditya Verma (it easy to understand so recommended to watch video)
// this is the same logic as nearest smaller to right but we go from left to right
// and we don't need to reverse the vector at the end
// because we are already going from left to right
// and the order of elements is maintained as we process from left to right
// nearest smaller to left
//also here check s.top() < arr[i] instead of s.top() <= arr[i]
// because we want to find the nearest smaller element to the left
// and we don't want to include the current element itself
// if we use s.top() <= arr[i] then it will include the current element itself
// and it will not be the nearest smaller element to the left
// so we use s.top() < arr[i] to find the nearest smaller element to the left

vector<int> v;
stack<int> s;
void nearestSmallerToLeft(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        // Check if stack is empty then push -1 in vector
        if (s.empty()) {
            v.push_back(-1);
        } else if (!s.empty() && s.top() < arr[i]) {   
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
    // No need to reverse the vector as we are going from left to right
    // The order of elements is maintained as we process from left to right
}