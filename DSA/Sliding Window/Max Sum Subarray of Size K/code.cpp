#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumSumSubarray(int k, vector<int> &arr) {
        int n = arr.size();
        int low = 0;
        int high = 0;
        int sum = 0;
        int result = 0;
        while (high < n) {
            sum += arr[high];
            if (high - low + 1 == k) {

                result = max(result, sum);
                sum -= arr[low];
                low++;
            }
            high++;
        }
        return result;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {100, 200, 300, 400};
    int k = 2;
    cout << obj.maximumSumSubarray(k, arr);
    return 0;
}




/*
https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

┌──(mahecd "/home/maheshpatil369/Desktop/DSA C++/DSA/Sliding Window/Max Sum Subarray of Size K/" && g++ code.cpp -o      && "/home/maheshpatil369/Desktop/DSA C++/DSA/Sliding Window/Max Sum Subarray of Size K/"code
700 
*/