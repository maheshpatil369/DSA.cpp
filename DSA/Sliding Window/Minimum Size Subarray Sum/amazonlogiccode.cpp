#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = 0;
        int sum = 0;
        int result = INT_MAX;
        while (high < n) {
            // Hire amazon like exmple hire and fire 
            sum += nums[high];

            // Fire
            while (sum >= target) {
                result = min(result, high - low + 1);
                sum -= nums[low];   // sum = sum - nums[low];
                low++;
            }
            high++;
        }
        return (result == INT_MAX) ? 0 : result;
    }
};

int main() {
    Solution obj;
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << obj.minSubArrayLen(target, nums);
    return 0;
}






/*

https://leetcode.com/problems/minimum-size-subarray-sum/submissions/2063574519/



┌──(mahecd "/home/maheshpatil369/Desktop/DSA C++/DSA/Sliding Window/Minimum Size Subarray Sum/" && g++                     -o                 && "/home/maheshpatil369/Desktop/DSA C++/DSA/Sliding Window/Minimum Size Subarray Sum/"amazonlogiccode
2       

*/