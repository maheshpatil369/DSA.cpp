#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution obj;
    vector<vector<int>> ans = obj.threeSum(nums);
    for (auto &triplet : ans) {
        cout << "[ ";
        for (int x : triplet)
            cout << x << " ";
        cout << "]" << endl;
    }
    return 0;
}







/*
LeetCode No. 15
https://leetcode.com/problems/3sum/description/


┌──(mahecd "/home/maheshpatil369/Desktop/DSA C++/DSA/Pattern: Two Pointers/Three Sum/" && g++          -o      && "/home/maheshpatil369/Desktop/DSA C++/DSA/Pattern: Two Pointers/Three Sum/"code
[ -1 -1 2 ]
[ -1 0 1 ]
              
*/