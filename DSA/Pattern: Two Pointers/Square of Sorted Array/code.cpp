#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        int size = a.size();

        vector<int> neg;
        vector<int> pos;

        for (int i = 0; i < size; i++) {
            if (a[i] < 0) {
                neg.push_back(a[i]);
            } else {
                pos.push_back(a[i]);
            }
        }

        if (neg.size() == 0) {
            for (int i = 0; i < pos.size(); i++) {
                pos[i] = pos[i] * pos[i];
            }
            return pos;
        }

        if (pos.size() == 0) {
            for (int i = 0; i < neg.size(); i++) {
                neg[i] = neg[i] * neg[i];
            }
            reverse(neg.begin(), neg.end());
            return neg;
        }

        int n = neg.size();
        int m = pos.size();

        for (int i = 0; i < n; i++) {
            neg[i] = neg[i] * neg[i];
        }

        reverse(neg.begin(), neg.end());

        for (int i = 0; i < m; i++) {
            pos[i] = pos[i] * pos[i];
        }

        vector<int> res(n + m);

        int i = 0, j = 0, id = 0;

        while (i < n && j < m) {
            if (neg[i] < pos[j]) {
                res[id++] = neg[i++];
            } else {
                res[id++] = pos[j++];
            }
        }

        while (i < n) {
            res[id++] = neg[i++];
        }

        while (j < m) {
            res[id++] = pos[j++];
        }

        return res;
    }
};

int main() {
    vector<int> a = {-7, -3, -1, 4, 8, 12};

    cout << "Original Array: ";
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;

    Solution obj;
    vector<int> ans = obj.sortedSquares(a);

    cout << "Sorted Squares: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}





/*

Leetcode number  977 
https://leetcode.com/problems/squares-of-a-sorted-array/description/

┌──(mahecd "/home/maheshpatil369/Desktop/DSA C++/DSA/Pattern: Two Pointers/Square of Sorted Array/" && g++ code.cpp -o      && "/home/maheshpatil369/Desktop/DSA C++/DSA/Pattern: Two Pointers/Square of Sorted Array/"code
Original Array: -7 -3 -1 4 8 12 
Sorted Squares: 1 9 16 49 64 144 
                                    
*/