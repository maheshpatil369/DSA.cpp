#include <iostream>

using namespace std;

int hellooChai(){
 return 10;
}

int main(){
    
   // Lambda Function
    // A lambda is an anonymous (nameless) function.
    // It can be created and used directly inside another function.
    auto preparedChai = [](int cups){
        cout << "Preparing " << cups << " cups of tea" << endl;
    };
    
        // Calling the lambda Fun...
    preparedChai(4);
    
    return 0;
}




// output
//   Running] cd "/home/maheshpatil369/Desktop/DSA C++/Learn C++/Day .. Functions/" && g++ myFunFour.cpp -o myFunFour && "/home/maheshpatil369/Desktop/DSA C++/Learn C++/Day .. Functions/"myFunFour
// Preparing 4 cups of tea
