#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumSum(vector<int>& arr) {
    int keep = arr[0];   // Maximum sum ending here without deletion
    int del = 0;         // Maximum sum ending here after one deletion
    int ans = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        int newDel = max(keep, del + arr[i]);
        int newKeep = max(arr[i], keep + arr[i]);

        keep = newKeep;
        del = newDel;

        ans = max(ans, max(keep, del));
    }

    return ans;
}

int main() {
    vector<int> arr = {1, -2, 0, 3};

    cout << "Maximum Sum = " << maximumSum(arr);

    return 0;
}










/*
https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/description/

┌──(mahecd "/home/maheshpatil369/Desktop/Learn DSA/DSA.cpp/DSA/Kadanes Pattern/Maximum subarray sum with one deletion/" && g++          -o      && "/home/maheshpatil369/Desktop/Learn DSA/DSA.cpp/DSA/Kadanes Pattern/Maximum subarray sum with one deletion/"code
Maximum Sum = 4                                                                                                                                                                              
┌──(maheshpatil369㉿kali)-[~/…/DSA.cpp/DSA/Kadanes Pattern/Maximum subarray sum with one deletion]
└─$ */