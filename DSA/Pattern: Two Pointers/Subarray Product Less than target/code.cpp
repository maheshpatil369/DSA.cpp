#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)
            return 0;
        int left = 0;
        int product = 1;
        int count = 0;

        for (int right = 0; right < nums.size(); right++) {
            product *= nums[right];

            while (product >= k) {
                product /= nums[left];
                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }
};

int main() {
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    Solution obj;
    int ans = obj.numSubarrayProductLessThanK(nums, k);
    cout << "Number of subarrays: " << ans << endl;
    return 0;
}





/*
Leetcode No. 713
https://leetcode.com/problems/subarray-product-less-than-k/description/

┌──(mahecd "/home/maheshpatil369/Desktop/DSA C++/DSA/Pattern: Two Pointers/Subarray Product Less than target/" && g++ code.cpp -o      && "/home/maheshpatil369/Desktop/DSA C++/DSA/Pattern: Two Pointers/Subarray Product Less than target/"code
Number of subarrays: 8
                       
*/