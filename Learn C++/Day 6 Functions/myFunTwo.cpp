#include <iostream>

using namespace std;


void pourChai(int cups){
    cups = cups + 5;
    cout << "Poured cups: " << cups << endl;
}

int main(){
    
    int cups = 2;
       // Function call
    // A COPY of cups is sent to the function
    // Original cups remains unchanged
    pourChai(cups);
      // Printing the original variable
    // It is still 2 because only the copy was modified
    cout << "Total cups are " << cups << endl;
    return 0;
}




// Output 
// [Running] cd "/home/maheshpatil369/Desktop/DSA C++/Learn C++/Day .. Functions/" && g++ myFunTwo.cpp -o myFunTwo && "/home/maheshpatil369/Desktop/DSA C++/Learn C++/Day .. Functions/"myFunTwo
// Poured cups: 7
// Total cups are 2