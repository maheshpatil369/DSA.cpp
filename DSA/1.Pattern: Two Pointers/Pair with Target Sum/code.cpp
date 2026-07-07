#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target)
                return {left + 1, right + 1};
            else if (sum < target)
                left++;
            else
                right--;
        }

        return {};
    }
};

int main() {
    Solution s;

    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> ans = s.twoSum(nums, target);

    for (int x : ans)
        cout << x << " ";

    return 0;
}