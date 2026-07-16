#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

//---------------------------------------------------------
void explainGreater(){
    cout<<"\n===== greater<int>() =====\n";

    vector<int> v={5,2,9,1};

    cout<<"Before : ";
    for(int x:v) cout<<x<<" ";

    sort(v.begin(),v.end(),greater<int>());

    cout<<"\nAfter  : ";
    for(int x:v) cout<<x<<" ";

    cout<<"\nOutput : 9 5 2 1\n";
}

//---------------------------------------------------------
void explainLess(){
    cout<<"\n===== less<int>() =====\n";

    vector<int> v={5,2,9,1};

    sort(v.begin(),v.end(),less<int>());

    for(int x:v) cout<<x<<" ";

    cout<<"\nOutput : 1 2 5 9\n";
}

//---------------------------------------------------------
void explainArithmeticFunctors(){
    cout<<"\n===== Arithmetic Functors =====\n";

    plus<int> add;
    minus<int> sub;
    multiplies<int> mul;
    divides<int> div;
    modulus<int> mod;
    negate<int> neg;

    cout<<"plus        : "<<add(10,5)<<endl;
    cout<<"minus       : "<<sub(10,5)<<endl;
    cout<<"multiplies  : "<<mul(10,5)<<endl;
    cout<<"divides     : "<<div(10,5)<<endl;
    cout<<"modulus     : "<<mod(10,3)<<endl;
    cout<<"negate      : "<<neg(10)<<endl;
}

//---------------------------------------------------------
void explainComparisonFunctors(){
    cout<<"\n===== Comparison Functors =====\n";

    equal_to<int> eq;
    not_equal_to<int> neq;
    greater<int> gt;
    less<int> lt;
    greater_equal<int> ge;
    less_equal<int> le;

    cout<<"equal_to(5,5)        : "<<eq(5,5)<<endl;
    cout<<"not_equal_to(5,4)    : "<<neq(5,4)<<endl;
    cout<<"greater(8,3)         : "<<gt(8,3)<<endl;
    cout<<"less(3,8)            : "<<lt(3,8)<<endl;
    cout<<"greater_equal(5,5)   : "<<ge(5,5)<<endl;
    cout<<"less_equal(5,6)      : "<<le(5,6)<<endl;
}

//---------------------------------------------------------
class CompareDescending{
public:
    bool operator()(int a,int b){
        return a>b;
    }
};

void explainCustomFunctor(){
    cout<<"\n===== Custom Functor =====\n";

    vector<int> v={7,1,5,9};

    sort(v.begin(),v.end(),CompareDescending());

    for(int x:v)
        cout<<x<<" ";

    cout<<"\nOutput : 9 7 5 1\n";
}

//---------------------------------------------------------
void explainLambda(){
    cout<<"\n===== Lambda Function =====\n";

    vector<int> v={7,1,5,9};

    sort(v.begin(),v.end(),
    [](int a,int b){
        return a>b;
    });

    for(int x:v)
        cout<<x<<" ";

    cout<<"\nOutput : 9 7 5 1\n";
}

//---------------------------------------------------------
int main(){

    explainGreater();
    explainLess();
    explainArithmeticFunctors();
    explainComparisonFunctors();
    explainCustomFunctor();
    explainLambda();

    return 0;
}



/*

┌──(mahecd "/home/maheshpatil369/Desktop/Learn DSA/DSA.cpp/Learn C++/C++ STL/Functions/" && g++ code.cpp -o code && "/home/maheshpatil369/Desktop/Learn DSA/DSA.cpp/Learn C++/C++ STL/Functions/"code

===== greater<int>() =====
Before : 5 2 9 1 
After  : 9 5 2 1 
Output : 9 5 2 1

===== less<int>() =====
1 2 5 9 
Output : 1 2 5 9

===== Arithmetic Functors =====
plus        : 15
minus       : 5
multiplies  : 50
divides     : 2
modulus     : 1
negate      : -10

===== Comparison Functors =====
equal_to(5,5)        : 1
not_equal_to(5,4)    : 1
greater(8,3)         : 1
less(3,8)            : 1
greater_equal(5,5)   : 1
less_equal(5,6)      : 1

===== Custom Functor =====
9 7 5 1 
Output : 9 7 5 1

===== Lambda Function =====
9 7 5 1 
Output : 9 7 5 1
                                                                                                                                                                              
┌──(maheshpatil369㉿kali)-[~/…/DSA.cpp/Learn C++/C++ STL/Functions]
└─$ 
*/