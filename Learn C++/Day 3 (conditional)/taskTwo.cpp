#include <iostream>
using namespace std;

int main () {
    int hour;
    cout << "Send me hours between (1-23)" << endl;
    cin >> hour;

    if (hour >=8 && hour <= 18) {
        cout << "Shop is Open!" << endl;
    } else {
        cout << "Shop is Closed" <<endl;
    };
    return 0;
}




// Output 
// Green Tea
// your Green Tea is selected
                                                                                                                                                                                              
// ┌──(maheshpatil369㉿kali)-[~/Desktop/DSA C++/Learn C++/Day 3 (conditional)]
// └─$ ./taskTwo
// Send me hours between (1-23)
// 12
// Shop is Open!
                                                                                                                                                                                              
// ┌──(maheshpatil369㉿kali)-[~/Desktop/DSA C++/Learn C++/Day 3 (conditional)]
// └─$ ./taskTwo
// Send me hours between (1-23)
// 43
// Shop is Closed
                                                                                                                                                                                              
// ┌──(maheshpatil369㉿kali)-[~/Desktop/DSA C++/Learn C++/Day 3 (conditional)]
// └─$ 