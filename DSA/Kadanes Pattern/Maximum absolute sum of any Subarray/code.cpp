#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int maxAbsoluteSum(vector<int>& nums) {
    int currMax = 0, maxSum = 0;
    int currMin = 0, minSum = 0;

    for (int x : nums) {
        // Maximum subarray sum (Kadane)
        currMax = max(x, currMax + x);
        maxSum = max(maxSum, currMax);

        // Minimum subarray sum
        currMin = min(x, currMin + x);
        minSum = min(minSum, currMin);
    }

    return max(maxSum, abs(minSum));
}

int main() {
    vector<int> nums = {2, -5, 1, -4, 3, -2};

    cout << "Maximum Absolute Sum = " << maxAbsoluteSum(nums) << endl;

    return 0;
}



/*
leetcode 1749 

               
┌──(mahecd "/home/maheshpatil369/Desktop/Learn DSA/DSA.cpp/DSA/Kadanes Pattern/Maximum absolute sum of any Subarray/" && g++ code.cpp -o      && "/home/maheshpatil369/Desktop/Learn DSA/DSA.cpp/DSA/Kadanes Pattern/Maximum absolute sum of any Subarray/"code
Maximum Absolute Sum = 8
                                                                                                                                                                              
┌──(maheshpatil369㉿kali)-[~/…/DSA.cpp/DSA/Kadanes Pattern/Maximum absolute sum of any Subarray]
└─$ 

*/