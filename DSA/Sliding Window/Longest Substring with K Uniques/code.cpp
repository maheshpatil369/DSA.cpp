// Fruit Basket and Trees Logic
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int longestKSubstr(string s, int k) {

    unordered_map<char, int> freq;

    int low = 0;
    int result = -1;
    int start = -1;   // Starting index of longest substring

    for (int high = 0; high < s.length(); high++) {
  // Add current fruit (character) into the basket
        freq[s[high]]++;
        // remove fruits from the left
        while (freq.size() > k) {

            freq[s[low]]--;

            if (freq[s[low]] == 0) {
                freq.erase(s[low]);
            }

            low++;
        }
        // update the longest substring
        if (freq.size() == k) {

            if (high - low + 1 > result) {
                result = high - low + 1;
                start = low;
            }
        }
    }

    if (result != -1) {
        cout << "Longest Substring = " << s.substr(start, result) << endl;
        cout << "Start Index = " << start << endl;
        cout << "End Index = " << start + result - 1 << endl;
    } else {
        cout << "No valid substring found." << endl;
    }
    return result;
}

int main() {

    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;
    cout << "Enter k: ";
    cin >> k;
    cout << "Longest substring length = " << longestKSubstr(s, k);

    return 0;
}




/*
https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

┌──(mahecd "/home/maheshpatil369/Desktop/DSA C++/DSA/Sliding Window/Longest Substring with K Uniques/" && g++ code.cpp -o code && "/home/maheshpatil369/Desktop/DSA C++/DSA/Sliding Window/Longest Substring with K Uniques/"code
Enter string: aawwwwwnnjwjjwnnsndje
Enter k: 4
Longest substring length = Longest Substring = aawwwwwnnjwjjwnn
Start Index = 0
End Index = 15
16    
*/