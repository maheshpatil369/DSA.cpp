#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            int tempMax = max({nums[i],
                               nums[i] * maxProd,
                               nums[i] * minProd});

            int tempMin = min({nums[i],
                               nums[i] * maxProd,
                               nums[i] * minProd});

            maxProd = tempMax;
            minProd = tempMin;

            ans = max(ans, maxProd);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {2, 3, -2, 4};

    cout << "Maximum Product Subarray = "
         << obj.maxProduct(nums) << endl;

    return 0;
}