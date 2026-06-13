#include <iostream>
#include <string>
using namespace std;

int main () {
    string teaOrder;
    cout <<"Enter your Tea Name" << endl;
    getline(cin, teaOrder);

    if (teaOrder == "Green Tea"){
    cout << "your Green Tea is selected" << endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
} else {
    cout << "Invalid" << endl;
}
return 0;
}



// Output 
// ┌──(maheshpatil369㉿kali)-[~/Desktop/DSA C++/Learn C++/Day 3 (conditional)]
// └─$ ./taskOne
// Enter your Tea Name
// Green Tea
// your Green Tea is selected