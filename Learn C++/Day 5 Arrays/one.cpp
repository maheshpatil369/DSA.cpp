#include <iostream>
using namespace std;

int main(){
    int chaiTemperature[5] = {85, 90, 88, 92, 89};

    cout << "Chai temperature: ";
    for(int i = 0 ; i < 5 ; i++ ){
        cout << chaiTemperature[i] << " degree C \n";
    }

    return 0;
}




// Output 
// [Running] cd "/home/maheshpatil369/Desktop/DSA C++/Learn C++/Day 5 Arrays/" && g++ one.cpp -o one && "/home/maheshpatil369/Desktop/DSA C++/Learn C++/Day 5 Arrays/"one
// Chai temperature: 85 degree C 
// 90 degree C 
// 88 degree C 
// 92 degree C 
// 89 degree C 

// [Done] exited with code=0 in 0.459 seconds