#include <iostream>
using namespace std;

int checkTemperature(int temperature){
    return temperature;
}

//declaration of function
void serveChai(int cups);


void makeChai(){
    cout << "Boiling water, adding tea leaves, straining...";
}

void serveChai(string teaType = "Masala Tea"){
    int cups = 4;
    cout << "Serving " << teaType << endl;
}

void serveChai(int cup, int tealeaves){

}


int main(){
    int temp = checkTemperature(50);

    serveChai();
    return 0;
}

// defination of function
void serveChai(int cups){
    cout << "Serving " << cups << " of chai";
}




// Output 
// [Running] cd "/home/maheshpatil369/Desktop/DSA C++/Learn C++/Day .. Functions/" && g++ myFunction.cpp -o myFunction && "/home/maheshpatil369/Desktop/DSA C++/Learn C++/Day .. Functions/"myFunction
// Serving Masala Tea