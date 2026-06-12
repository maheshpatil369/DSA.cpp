#include <iostream>
using namespace std;


// Relational Operators  (>= , <= )
// challange: A tea shop offers a loyalty program. Customers who buy more than 20 cups of tea bags a special "Gold" badge, and thoes who but 10 to 20 cups gets a silver badge. write a program to display the badge  they will recived based on the number of cups they buy.

int main () {
    int cups; 
    cout << "Enter the number of cups you have"  << endl;
    cin >> cups;

    if (cups > 20) {
        cout << "You will get a GOLD badge"     << endl ;
    } else if (cups >= 10 && cups <= 20) {      // cups greater than 10 and cups less than 20 (&& is and)
        cout << "You will get SILVER badge" <<endl;
    } else {
        cout << "NO BADGE for you" <<endl;
    }

    return 0;
}





// Output 

// ──(maheshpatil369㉿kali)-[~/Desktop/DSA C++/Learn C++/Day 2]
// └─$ ./relation
// Enter the number of cups you have
// 20
// You will get SILVER badge
                                                                                                                                                                                              
// ┌──(maheshpatil369㉿kali)-[~/Desktop/DSA C++/Learn C++/Day 2]
// └─$ ./relation
// Enter the number of cups you have
// 2
// NO BADGE for you
                                                                                                                                                                                              
// ┌──(maheshpatil369㉿kali)-[~/Desktop/DSA C++/Learn C++/Day 2]
// └─$ ./relation
// Enter the number of cups you have
// 23
// You will get a GOLD badge
                                                                                                                                                        