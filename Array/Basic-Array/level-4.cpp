#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {4, 5, 1, 2, 1, 4, 2};
    //  parent of all these logic developed for solving array and string problems
    /*unordered_set<int> seen;
    for(int x : arr) {
    if(seen.count(x)) {
        // duplicate found
    }
    seen.insert(x);
}
*/


// First non-repeating element in an array
{
    unordered_map<int,int> freq;
    for(int x : arr) freq[x]++;
    int firstNonRep = -1;
    for(int x : arr) {
        if(freq[x] == 1) { firstNonRep = x; break; }
    }
    cout << "First non-repeating element: " << firstNonRep << endl;
}

// First repeating element in an array
{
    unordered_set<int> seen;
    int firstRep = -1;
    for(int x : arr) {
        if(seen.count(x)) { firstRep = x; break; }
        seen.insert(x);
    }
    cout << "First repeating element: " << firstRep << endl;
}

//First non-repeating character in a string
{
    string s = "geeksforgeeks";
    unordered_map<char,int> freq;
    for(char c : s) freq[c]++;
    char firstNonRep = '\0';
    for(char c : s) {
        if(freq[c] == 1) { firstNonRep = c; break; }
    }
    cout << "First non-repeating character: " << firstNonRep << endl;
}

//Contains Duplicate II (within distance k)
{
    int k = 3; // distance
    unordered_set<int> window;
    bool hasDup = false;
    for(int i = 0; i < arr.size(); i++) {
        if(window.count(arr[i])) { hasDup = true; break; }
        window.insert(arr[i]);
        if(i >= k) window.erase(arr[i - k]); // maintain window size
    }
    cout << "Contains duplicate within distance " << k << "? " 
         << (hasDup ? "Yes" : "No") << endl;
}

// Smallest window containing all unique elements
vector<int> arr = {1, 2, 2, 3, 1};
unordered_set<int> uniq(arr.begin(), arr.end()); // all distinct
int need = uniq.size();

unordered_map<int,int> freq;
int left = 0, minLen = INT_MAX;
for (int right = 0; right < arr.size(); right++) {
    freq[arr[right]]++;
    while (freq.size() == need) {
        minLen = min(minLen, right - left + 1);
        if (--freq[arr[left]] == 0) freq.erase(arr[left]);
        left++;
    }
}
cout << "Smallest window with all unique elements: " << minLen << endl;


//Check if two strings are anagrams
string a = "listen", b = "silent";
if (a.size() != b.size()) cout << "Not anagram\n";
else {
    unordered_map<char,int> freq;
    for (char c : a) freq[c]++;
    for (char c : b) freq[c]--;
    bool isAnagram = true;
    for (auto &p : freq) if (p.second != 0) isAnagram = false;
    cout << "Anagram? " << (isAnagram ? "Yes" : "No") << endl;
}


//Find common characters in all words
vector<string> words = {"bella","label","roller"};
vector<int> minFreq(26, INT_MAX);

for (string w : words) {
    vector<int> freq(26,0);
    for (char c : w) freq[c-'a']++;
    for (int i = 0; i < 26; i++) {
        minFreq[i] = min(minFreq[i], freq[i]);
    }
}

cout << "Common characters: ";
for (int i = 0; i < 26; i++) {
    for (int j = 0; j < minFreq[i]; j++) cout << char('a'+i) << " ";
}
cout << endl;

//Check if two arrays are disjoint
vector<int> A = {1, 2, 3}, B = {4, 5, 6};
unordered_set<int> s(A.begin(), A.end());
bool disjoint = true;
for (int x : B) if (s.count(x)) { disjoint = false; break; }
cout << "Arrays disjoint? " << (disjoint ? "Yes" : "No") << endl;


// Stream duplicate detection (online problem)
unordered_set<int> seen;
vector<int> stream = {1, 2, 3, 2, 4, 1};

for (int x : stream) {
    if (seen.count(x)) cout << "Duplicate detected: " << x << endl;
    else seen.insert(x);
}





return 0;
}