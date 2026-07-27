#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArraySum(vector<int>& arr) {
        int currMin = arr[0];
        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            currMin = min(arr[i], currMin + arr[i]);
            ans = min(ans, currMin);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {3, -4, 2, -3, -1, 7, -5};

    cout << "Minimum Subarray Sum = " << obj.minSubArraySum(arr) << endl;

    return 0;
}