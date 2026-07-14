#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> freq;

    int low = 0;
    int ans = 0;

    for (int high = 0; high < s.size(); high++)
    {
        // Add current character
        freq[s[high]]++;

        // Remove duplicate characters
        while (freq[s[high]] > 1)
        {
            freq[s[low]]--;
            low++;
        }

        // Update maximum length
        ans = max(ans, high - low + 1);
    }

    return ans;
}

int main()
{
    string s = "abcabcbb";
    cout << "Longest Substring Length: "
         << lengthOfLongestSubstring(s);

    return 0;
}




/*

https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

┌──(mahecd "/home/maheshpatil369/Desktop/Learn DSA/DSA.cpp/DSA/Sliding Window/Longest Substring Without Repeating Characters/" && g++ code.cpp -o      && "/home/maheshpatil369/Desktop/Learn DSA/DSA.cpp/DSA/Sliding Window/Longest Substring Without Repeating Characters/"code


*/