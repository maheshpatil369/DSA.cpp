#include <iostream>

using namespace std;

int globalChaiStock = 100;
// '&' means Pass By Reference
// The original variable from main() will be modified
void pourChai(int &cups){
    int test = 9;
    cups = cups + 5;
    
    cout << "Poured cups: " << cups << endl;
}



int main(){
    
    int cups = 2;
    // Since '&' is used, no copy is created
    pourChai(cups);
    cout << "Total cups are " << cups << endl;
    return 0;
}





// Output 

// [Running] cd "/home/maheshpatil369/Desktop/DSA C++/Learn C++/Day .. Functions/" && g++ myFunThree.cpp -o myFunThree && "/home/maheshpatil369/Desktop/DSA C++/Learn C++/Day .. Functions/"myFunThree
// Poured cups: 7
// Total cups are 7