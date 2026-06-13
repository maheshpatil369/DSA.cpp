#include <iostream>
using namespace std;

int main () {
    int cups ;
    double pricePerCup = 2.5, totalPrice, discount;

    cout << "Enter the number of Cups"  << endl ;
    cin >> cups;

    totalPrice = pricePerCup * cups;

    if (cups >20) {
        discount = 0.20;
    } else if (cups >= 10 && cups <=20) {
        discount = 0.10;
    } else {
        discount = 0;
    }

    totalPrice -= (totalPrice*discount) ;
    cout << " Total price after discount is: "  << totalPrice << endl; 


  

return 0;
}



// Output 
// ┌──(maheshpatil369㉿kali)-[~/Desktop/DSA C++/Learn C++/Day 3 (conditional)]
// └─$ ./taskthree
// Enter the number of Cups
// 20
//  Total price after discount is: 45
                                                                                                                                                                                              
// ┌──(maheshpatil369㉿kali)-[~/Desktop/DSA C++/Learn C++/Day 3 (conditional)]
// └─$ ./taskthree
// Enter the number of Cups
// 9
//  Total price after discount is: 22.5
                                                                                                                                                                                              
// ┌──(maheshpatil369㉿kali)-[~/Desktop/DSA C++/Learn C++/Day 3 (conditional)]
// └─$ 