#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {10, 20, 30, 20, 40, 10};

    // 1. Check if array contains any duplicate
    {
        unordered_set<int> s;
        bool hasDuplicate = false;
        for (int x : arr) {
            if (s.count(x)) { hasDuplicate = true; break; }
            s.insert(x);
        }
        cout << "Contains duplicate? " << (hasDuplicate ? "Yes" : "No") << endl;
    }

    // 2. Print the first duplicate element
    {
        unordered_set<int> s;
        int firstDup = -1;
        for (int x : arr) {
            if (s.count(x)) { firstDup = x; break; }
            s.insert(x);
        }
        cout << "First duplicate: " << firstDup << endl;
    }

    // 3. Count the number of duplicate occurrences
    {
        unordered_set<int> s;
        int countDup = 0;
        for (int x : arr) {
            if (s.count(x)) countDup++;
            else s.insert(x);
        }
        cout << "Duplicate occurrences: " << countDup << endl;
    }

    // 4. Print all unique elements
    {
        unordered_set<int> s(arr.begin(), arr.end());
        cout << "Unique elements: ";
        for (int x : s) cout << x << " ";
        cout << endl;
    }

    // 5. Check if all elements are distinct
    {
        unordered_set<int> s(arr.begin(), arr.end());
        cout << "All distinct? " << (s.size() == arr.size() ? "Yes" : "No") << endl;
    }

    // 6. Remove duplicates while preserving order
    {
        unordered_set<int> s;
        vector<int> result;
        for (int x : arr) {
            if (!s.count(x)) {
                s.insert(x);
                result.push_back(x);
            }
        }
        cout << "After removing duplicates: ";
        for (int x : result) cout << x << " ";
        cout << endl;
    }

    // 7. Count the number of unique elements
    {
        unordered_set<int> s(arr.begin(), arr.end());
        cout << "Number of unique elements: " << s.size() << endl;
    }

    return 0;
}
