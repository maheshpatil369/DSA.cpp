#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main () {
  vector<int> arr = {5 , 3, 6};

  sort(arr.begin(), arr.end() );
  int target = 9;
  int i = 0;
  int j = arr.size() - 1;

  while (i<j) {
    int sum = arr[i] + arr[j];

    if (sum == target)
    {
        cout << "[" << i << ", " << j << "]" << endl;
            break;
  }

    if (sum > target)
    {
        j++;
        continue;
    }

    if (sum < target)
    {
        i++;
        continue;
    }
  }



}








/*

https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/



┌──(mahecd "/home/maheshpatil369/Desktop/DSA C++/DSA/Pattern: Two Pointers/Pair with Target Sum/" && g++ code.cpp -o code && "/home/maheshpatil369/Desktop/DSA C++/DSA/Pattern: Two Pointers/Pair with Target Sum/"code
[0, 2]
                                                                                                                                                                              
┌──(maheshpatil369㉿kali)-[~/…/DSA C++/DSA/Pattern: Two Pointers/Pair with Target Sum]
└─$ 
*/