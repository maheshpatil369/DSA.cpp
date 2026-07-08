#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> numbers = {1, 1, 2, 2, 3, 3, 6, 7, 7};

    int unique = 1;
    int current = 1;

    while (current < numbers.size())
    {
        if (numbers[current] == numbers[current - 1])
        {
            current++;
        }
        else
        {
            numbers[unique] = numbers[current];
            unique++;
            current++;
        }
    }

    cout << "Unique Elements: ";

    for (int i = 0; i < unique; i++)
    {
        cout << numbers[i] << " ";
    }

    return 0;
}




/*        

https://leetcode.com/problems/remove-duplicates-from-sorted-array/


┌──(mahecd "/home/maheshpatil369/Desktop/DSA C++/DSA/Pattern: Two Pointers/Remove Duplicates/" && g++ code.cpp -o code && "/home/maheshpatil369/Desktop/DSA C++/DSA/Pattern: Two Pointers/Remove Duplicates/"code
Unique Elements: 1 2 3 6 7                                                                                                                                                                               
┌──(maheshpatil369㉿kali)-[~/…/DSA C++/DSA/Pattern: Two Pointers/Remove Duplicates]
└─$ 
*/
