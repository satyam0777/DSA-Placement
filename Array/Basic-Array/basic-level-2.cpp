#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr1 = {10, 20, 30, 40, 50};
    vector<int> arr2 = {30, 40, 50, 60, 70};

    // 8. Check if an element x exists in the array
    {
        int x = 40;  // element to check
        unordered_set<int> s(arr1.begin(), arr1.end());
        cout << "Is " << x << " present? " << (s.count(x) ? "Yes" : "No") << endl;
    }

    // 9. Multiple queries: check if each query element exists
    {
        vector<int> queries = {15, 20, 70};
        unordered_set<int> s(arr1.begin(), arr1.end());
        cout << "Query results: ";
        for (int q : queries) {
            cout << (s.count(q) ? "Yes " : "No ");
        }
        cout << endl;
    }

    // 10. Union of two arrays
    {
        unordered_set<int> s(arr1.begin(), arr1.end());
        s.insert(arr2.begin(), arr2.end()); // add all from arr2
        cout << "Union: ";
        for (int x : s) cout << x << " ";
        cout << endl;
    }

    // 11. Intersection of two arrays
    {
        unordered_set<int> s(arr1.begin(), arr1.end());
        cout << "Intersection: ";
        for (int x : arr2) {
            if (s.count(x)) cout << x << " ";
        }
        cout << endl;
    }

    // 12. Elements in arr1 but not in arr2 (Difference: A - B)
    {
        unordered_set<int> s(arr2.begin(), arr2.end());
        cout << "A - B: ";
        for (int x : arr1) {
            if (!s.count(x)) cout << x << " ";
        }
        cout << endl;
    }

    // 13. Elements appearing in both arrays at least once
    {
        unordered_set<int> s1(arr1.begin(), arr1.end());
        unordered_set<int> s2(arr2.begin(), arr2.end());
        cout << "Elements in both: ";
        for (int x : s1) {
            if (s2.count(x)) cout << x << " ";
        }
        cout << endl;
    }

    // 14. Symmetric Difference (in A or B but not both)
    {
        unordered_set<int> s1(arr1.begin(), arr1.end());
        unordered_set<int> s2(arr2.begin(), arr2.end());

        cout << "Symmetric Difference: ";
        for (int x : s1) {
            if (!s2.count(x)) cout << x << " ";
        }
        for (int x : s2) {
            if (!s1.count(x)) cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
