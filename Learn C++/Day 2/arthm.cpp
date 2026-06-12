#include <iostream>
// #include <string>  not need
using namespace std;

int main (){
    
  
//Question logic :- Arithmetic operator (+ , -, *, / , %)
//Challenge: Create a program that calculate the total price of tea cups. The user inputs the number of cups they want and the price per cup. The program should calcuate the total price, apply a 5% discount if the total is above the certain amount, aand show the final result 


    int cups ;
    double pricepercut, totalprice, discountedprice;
    cout << "Enter the number of tea cup" << endl;
    cin >> cups;
    cout << "Enter the price per cup" << endl;
    cin >> pricepercut;

    totalprice = cups * pricepercut ;

    // apply 5% discount if total was above 100
    if (totalprice > 100 ){
        discountedprice = totalprice - (totalprice * 0.05);
        cout << "Discounted price is:" << discountedprice << endl;

    } else  {
       cout << "Total price is " << totalprice << endl;
       
    }

    return 0;
}






// Output :
// ┌──(maheshpatil369㉿kali)-[~/Desktop/DSA C++/Learn C++/Day 2]
// └─$ ./arthm    
// Enter the number of tea cup
// 30
// Enter the price per cup
// 12
// Discounted price is:342

// ┌──(maheshpatil369㉿kali)-[~/Desktop/DSA C++/Learn C++/Day 2]
// └─$ ./arthm
// Enter the number of tea cup
// 200 
// Enter the price per cup
// 70
// Discounted price is:13300