#include <iostream>
using namespace std;

int main () {
    int choice;
    double price;

    cout << "Select your tea\n" ;
    cout << "1. Green Tea\n" ;
    cout << "2. Lemon Tea\n" ;
    cout << "3. Oolong Tea\n" ;
    cout << "Enter your choice in number:\n" ;

    cin >> choice;

    switch (choice) {
        case 1: 
        price = 2.0;
        cout << "You selected Green Tea. Price:" << price << endl;
        break;
      
       case 2: 
        price = 3.0;
        cout << "You selected Leomon Tea. Price:" << price << endl;
        break;

       case 3: 
        price = 4.0;
        cout << "You selected Oolong Tea. Price:" << price << endl;
        break;

       default:
       cout << "Invalid Choice" << endl;
       break;
    }
return 0;
}




// Output 
// ┌──(maheshpatil369㉿kali)-[~/Desktop/DSA C++/Learn C++/Day 3 (conditional)]
// └─$ ./taskFour
// Select your tea
// 1. Green Tea
// 2. Lemon Tea
// 3. Oolong Tea
// Enter your choice in number:
// 1
// You selected Green Tea. Price:2
                                                                                                                                                                                              
// ┌──(maheshpatil369㉿kali)-[~/Desktop/DSA C++/Learn C++/Day 3 (conditional)]
// └─$ ./taskFour
// Select your tea
// 1. Green Tea
// 2. Lemon Tea
// 3. Oolong Tea
// Enter your choice in number:
// 2
// You selected Leomon Tea. Price:3
                                                                                                                                                                                              
// ┌──(maheshpatil369㉿kali)-[~/Desktop/DSA C++/Learn C++/Day 3 (conditional)]
// └─$ ./taskFour
// Select your tea
// 1. Green Tea
// 2. Lemon Tea
// 3. Oolong Tea
// Enter your choice in number:
// 3
// You selected Oolong Tea. Price:4
                                                                                                                                                                                              