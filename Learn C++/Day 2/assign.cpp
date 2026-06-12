#include <iostream>
using namespace std;

// Assignment Operator (+= , -= , */ , /= , %= )
// Challange: Write a program that allows a user to  input the number of tea bags they have. Assign additional bags to them based on certain conditions (eg. if they have fewer than 10 bags, give  them 5 extra). Update the original number using arithmetic operators.

int main () {
    int teaBags; 
    cout << "Enter the number of tea bags you have:" << endl; 
    cin >> teaBags; 

    if (teaBags < 10){
        // teaBags = teaBags + 5
        teaBags += 5;
    } 
    cout << "Your total bags are:" << teaBags;

    return 0;
}





// output 

// ┌──(maheshpatil369㉿kali)-[~/Desktop/DSA C++/Learn C++/Day 2]
// └─$ ./assign
// Enter the number of tea bags you have:
// 12
// Your total bags are:12                                                                                                                                                                                              
// ┌──(maheshpatil369㉿kali)-[~/Desktop/DSA C++/Learn C++/Day 2]
// └─$ ./assign
// Enter the number of tea bags you have:
// 4
// Your total bags are:9                                                                                                                                                                                              
// ┌──(maheshpatil369㉿kali)-[~/Desktop/DSA C++/Learn C++/Day 2]
// └─$ 