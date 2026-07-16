#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        // Left pointer -> window ka start
        int left = 0;

        // Window ke andar kitne 0 hain
        int zeroCount = 0;

        // Final answer store karega
        int maxLength = 0;

        // Right pointer ko pura array me chalao
        for (int right = 0; right < nums.size(); right++) {

            // Agar current element 0 hai,
            // to window me ek aur zero aa gaya
            if (nums[right] == 0) {
                zeroCount++;
            }

            // Agar window me allowed se zyada zero aa gaye
            // to window ko chhota karna padega
            while (zeroCount > k) {

                // Agar left side wala element 0 tha,
                // to wo window se bahar ja raha hai,
                // isliye zero count kam kar do
                if (nums[left] == 0) {
                    zeroCount--;
                }

                // Left pointer ko aage badhao
                left++;
            }

            // Ab window valid hai (zeroCount <= k)
            // Is window ki length nikal lo
            int currentLength = right - left + 1;

            // Maximum length update karo
            maxLength = max(maxLength, currentLength);
        }

        return maxLength;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    cout << "Maximum Consecutive Ones = "
         << obj.longestOnes(nums, k);

    return 0;
}




/*

https://leetcode.com/problems/max-consecutive-ones-iii/description/

──(mahecd "/home/maheshpatil369/Desktop/Learn DSA/DSA.cpp/DSA/Sliding Window/Max Consecutive Ones III/" && g++          -o      && "/home/maheshpatil369/Desktop/Learn DSA/DSA.cpp/DSA/Sliding Window/Max Consecutive Ones III/"code
Maximum Consecutive Ones = 6     
*/