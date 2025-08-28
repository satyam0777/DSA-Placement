#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 1, 4, 5};
    string str = "abcaabcd";

    // 15. Check if a subarray contains a duplicate
    {
        int l = 0, r = 4; // subarray arr[l..r]
        unordered_set<int> s;
        bool hasDup = false;
        for (int i = l; i <= r; i++) {
            if (s.count(arr[i])) { hasDup = true; break; }
            s.insert(arr[i]);
        }
        cout << "Subarray has duplicate? " << (hasDup ? "Yes" : "No") << endl;
    }

    // 16. Longest subarray with all distinct elements (sliding window)
    {
        unordered_set<int> s;
        int left = 0, maxLen = 0;
        for (int right = 0; right < arr.size(); right++) {
            while (s.count(arr[right])) {
                s.erase(arr[left++]); // shrink window
            }
            s.insert(arr[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        cout << "Longest distinct subarray length: " << maxLen << endl;
    }

    // 17. Shortest subarray that contains a duplicate
    {
        unordered_map<int,int> lastIndex;
        int minLen = INT_MAX;
        for (int i = 0; i < arr.size(); i++) {
            if (lastIndex.count(arr[i])) {
                minLen = min(minLen, i - lastIndex[arr[i]] + 1);
            }
            lastIndex[arr[i]] = i;
        }
        cout << "Shortest duplicate subarray length: " 
             << (minLen == INT_MAX ? -1 : minLen) << endl;
    }

    // 18. Longest substring with unique characters (sliding window)
    {
        unordered_set<char> s;
        int left = 0, maxLen = 0;
        for (int right = 0; right < str.size(); right++) {
            while (s.count(str[right])) {
                s.erase(str[left++]); // shrink
            }
            s.insert(str[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        cout << "Longest unique substring length: " << maxLen << endl;
    }

    // 19. Check if all characters in a string are unique
    {
        unordered_set<char> s;
        bool unique = true;
        for (char c : str) {
            if (s.count(c)) { unique = false; break; }
            s.insert(c);
        }
        cout << "String all unique? " << (unique ? "Yes" : "No") << endl;
    }

    // 20. Remove duplicate characters from a string
    {
        unordered_set<char> s;
        string result = "";
        for (char c : str) {
            if (!s.count(c)) {
                s.insert(c);
                result.push_back(c);
            }
        }
        cout << "String after removing duplicates: " << result << endl;
    }

  
       

    // 7. Find the first non-repeating element
    {
        unordered_map<int,int> freq;
        for (int x : arr) freq[x]++;
        int firstNonRep = -1;
        for (int x : arr) {
            if (freq[x] == 1) { firstNonRep = x; break; }
        }
        cout << "First non-repeating element: " << firstNonRep << endl;
    }

    // 8. Find the first repeating element
    {
        unordered_set<int> s;
        int firstRep = -1;
        for (int x : arr) {
            if (s.count(x)) { firstRep = x; break; }
            s.insert(x);
        }
        cout << "First repeating element: " << firstRep << endl;
    }

    // 9. Check if certain elements exist in the array
    vector<int> arr1 = {10, 20, 30, 40, 50};
    vector<int> arr2 = {30, 40, 50, 60, 70};
    {
        unordered_set<int> s(arr1.begin(), arr1.end());
        cout << "Elements in arr1: ";
        for (int x : arr1) {
            cout << (s.count(x) ? "Yes " : "No ");
        }
        cout << endl;
    }

    // 10. Concatenate two arrays
    {
        vector<int> concatenated;
        concatenated.reserve(arr1.size() + arr2.size());
        concatenated.insert(concatenated.end(), arr1.begin(), arr1.end());
        concatenated.insert(concatenated.end(), arr2.begin(), arr2.end());

        cout << "Concatenated array: ";
        for (int x : concatenated) cout << x << " ";
        cout << endl;
    }

    // 11. Difference of two arrays (A - B)
    {
        unordered_set<int> s(arr2.begin(), arr2.end());
        cout << "A - B: ";
        for (int x : arr1) {
            if (!s.count(x)) cout << x << " ";
        }
        cout << endl;
    }

    // 12. given a string with contain dubalicate charater , write the output in a way , like first it frequency then multipily with its charater like aaabb --> 3a2b
    {
        string str = "aaabb";
        unordered_map<char,int> freq;
        for (char c : str) freq[c]++;
        string result = "";
        for (auto& p : freq) {
            result += to_string(p.second) + p.first;
        }
        cout << "Transformed string: " << result << endl;
    }
    // 13. Given an array of integers, find the length of the longest consecutive elements sequence.
    {
        unordered_set<int> s(arr.begin(), arr.end());
        int longestStreak = 0;

        for (int num : arr) {
            if (!s.count(num - 1)) { // start of a sequence
                int currentNum = num;
                int currentStreak = 1;

                while (s.count(currentNum + 1)) {
                    currentNum++;
                    currentStreak++;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        cout << "Longest consecutive sequence length: " << longestStreak << endl;
    }

    // 14. Find the first missing positive integer
    {
        unordered_set<int> s(arr.begin(), arr.end());
        int firstMissing = 1;
        while (s.count(firstMissing)) firstMissing++;
        cout << "First missing positive integer: " << firstMissing << endl;
    }

    
