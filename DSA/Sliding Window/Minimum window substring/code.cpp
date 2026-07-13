#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;





class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);

        // Store frequency of characters of t
        for (char c : t)
            need[c]++;

        int low = 0;
        int count = t.size();
        int start = 0;
        int res = INT_MAX;

        for (int high = 0; high < s.size(); high++) {
            // Required character found
            if (need[s[high]] > 0)
                count--;

            // Add current character into window
            need[s[high]]--;

            // Window is valid
            while (count == 0) {

                if (high - low + 1 < res) {
                    res = high - low + 1;
                    start = low;
                }

                // Remove leftmost character
                need[s[low]]++;

                // Window becomes invalid
                if (need[s[low]] > 0)
                    count++;

                low++;
            }
        }
        if (res == INT_MAX)
            return "";
        return s.substr(start, res);
    }
};

int main() {
    Solution obj;
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;
    cout << "Minimum Window Substring: " << obj.minWindow(s, t) << endl;
    return 0;
}


/*

https://leetcode.com/problems/minimum-window-substring/description/

┌──(mahecd "/home/maheshpatil369/Desktop/DSA C++/DSA/Sliding Window/Minimum Window Substring/" && g++ code.cpp -o      && "/home/maheshpatil369/Desktop/DSA C++/DSA/Sliding Window/Minimum Window Substring/"code
Enter string s: 45248452
Enter string t: 452
Minimum Window Substring: 452
*/