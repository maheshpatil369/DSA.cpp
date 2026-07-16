#include <iostream>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:

    string minWindow(string s, string t) {

        if (t.size() > s.size())
            return "";

        unordered_map<char, int> need;
        unordered_map<char, int> window;

        // t ki frequency store karo
        for (char ch : t)
            need[ch]++;

        int required = need.size();
        int formed = 0;

        int left = 0;

        int minLength = INT_MAX;
        int start = 0;

        // Right pointer ko move karo
        for (int right = 0; right < s.size(); right++) {

            char ch = s[right];

            // Current character window me add karo
            window[ch]++;

            // Agar required frequency complete ho gayi
            if (need.count(ch) && window[ch] == need[ch]) {
                formed++;
            }

            // Jab tak window valid hai
            while (formed == required) {

                int currentLength = right - left + 1;

                // Chhoti window mil gayi
                if (currentLength < minLength) {
                    minLength = currentLength;
                    start = left;
                }

                // Left character remove karo
                char leftChar = s[left];

                window[leftChar]--;

                // Agar required frequency toot gayi
                if (need.count(leftChar) &&
                    window[leftChar] < need[leftChar]) {

                    formed--;
                }

                // Window shrink karo
                left++;
            }
        }

        if (minLength == INT_MAX)
            return "";

        return s.substr(start, minLength);
    }
};

int main() {

    Solution obj;

    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << obj.minWindow(s, t);

    return 0;
}


/*

https://leetcode.com/problems/minimum-window-substring/description/?envType=study-plan-v2&envId=top-interview-150

┌──(mahecd "/home/maheshpatil369/Desktop/Learn DSA/DSA.cpp/DSA/Sliding Window/Minimum Window Substring/" && g++ code.cpp -o      && "/home/maheshpatil369/Desktop/Learn DSA/DSA.cpp/DSA/Sliding Window/Minimum Window Substring/"code
BANC                                                                                                                                                                                              
*/