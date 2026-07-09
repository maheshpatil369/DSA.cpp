#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res(m + n);

        int i = 0;
        int j = 0;
        int id = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                res[id] = nums1[i];
                i++;
            } else {
                res[id] = nums2[j];
                j++;
            }
            id++;
        }

        while (i < m) {
            res[id] = nums1[i];
            i++;
            id++;
        }

        while (j < n) {
            res[id] = nums2[j];
            j++;
            id++;
        }

        for (int k = 0; k < m + n; k++) {
            nums1[k] = res[k];
        }
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};

    int m = 3;
    int n = 3;

    cout << "nums1 before merge: ";
    for (int x : nums1)
        cout << x << " ";
    cout << endl;

    cout << "nums2: ";
    for (int x : nums2)
        cout << x << " ";
    cout << endl;

    Solution obj;
    obj.merge(nums1, m, nums2, n);

    cout << "nums1 after merge: ";
    for (int x : nums1)
        cout << x << " ";
    cout << endl;

    return 0;
}





/*
leetcode 88
https://leetcode.com/problems/merge-sorted-array/

┌──(mahecd "/home/maheshpatil369/Desktop/DSA C++/DSA/Pattern: Two Pointers/Merge Sorted Array/" && g++ code.cpp -o code && "/home/maheshpatil369/Desktop/DSA C++/DSA/Pattern: Two Pointers/Merge Sorted Array/"code
nums1 before merge: 1 2 3 0 0 0 
nums2: 2 5 6 
nums1 after merge: 1 2 2 3 5 6 
                               

*/