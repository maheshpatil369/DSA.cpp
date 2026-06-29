#include <iostream>
using namespace std;
int main () {
    int n;
    cin>>n;
    int row = 1;
    while ( row<= n) {
        // first traiangle
        int space = n - row;
        while (space) {
            cout<< "  ";
            space = space - 1;
        }
        // 2nd traingle
        int j = 1;
        while (j <= row) {
            cout << j;
            j = j + 1;
        }
        // 3rd traingle
        int start = row - 1;
        while(start) {
            cout<< start ;
            start = start - 1;
        }
        cout<<endl;
        row = row + 1;
    }
}





// Output 
                                                                                                                                                                                              
// ┌──(maheshpatil369㉿kali)-[~/Desktop/DSA C++/Learn C++/pattern]
// └─$ ./Pattern7
// 8
//               1
//             121
//           12321
//         1234321
//       123454321
//     12345654321
//   1234567654321
// 123456787654321
                                                                                                                                                                                              
// ┌──(maheshpatil369㉿kali)-[~/Desktop/DSA C++/Learn C++/pattern]
// └─$ 
