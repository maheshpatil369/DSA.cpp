#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
    int totalSum = 0;

    int currMax = 0, maxSum = nums[0];
    int currMin = 0, minSum = nums[0];

    for (int x : nums) {
        totalSum += x;

        // Kadane for maximum subarray sum
        currMax = max(x, currMax + x);
        maxSum = max(maxSum, currMax);

        // Kadane for minimum subarray sum
        currMin = min(x, currMin + x);
        minSum = min(minSum, currMin);
    }

    // If all elements are negative
    if (maxSum < 0)
        return maxSum;

    // Maximum of normal and circular subarray
    return max(maxSum, totalSum - minSum);
}

int main() {
    vector<int> nums = {5, -3, 5};

    cout << "Maximum Circular Subarray Sum = "
         << maxSubarraySumCircular(nums) << endl;

    return 0;
}


/*
https://leetcode.com/problems/maximum-sum-circular-subarray/description/
*/