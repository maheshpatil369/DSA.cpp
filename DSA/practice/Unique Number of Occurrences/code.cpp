#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// https://leetcode.com/problems/unique-number-of-occurrences/description/


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int num : arr) {
            freq[num]++;
        }

        unordered_set<int> seen;

        for (auto it : freq) {
            if (seen.count(it.second)) {
                return false;
            }
            seen.insert(it.second);
        }

        return true;
    }
};