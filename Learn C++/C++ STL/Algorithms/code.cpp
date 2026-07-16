#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

//---------------------------------------------------------
void explainSort(){
    cout<<"\n===== sort() =====\n";
    vector<int> v={5,2,9,1};

    cout<<"Before : ";
    for(int x:v) cout<<x<<" ";

    sort(v.begin(),v.end());

    cout<<"\nAfter  : ";
    for(int x:v) cout<<x<<" ";

    cout<<"\nOutput : 1 2 5 9\n";
}

//---------------------------------------------------------
void explainReverse(){
    cout<<"\n\n===== reverse() =====\n";
    vector<int> v={1,2,3,4};

    reverse(v.begin(),v.end());

    for(int x:v) cout<<x<<" ";

    cout<<"\nOutput : 4 3 2 1\n";
}

//---------------------------------------------------------
void explainFind(){
    cout<<"\n===== find() =====\n";

    vector<int> v={10,20,30,40};

    auto it=find(v.begin(),v.end(),30);

    if(it!=v.end())
        cout<<"30 Found at Index "<<it-v.begin()<<endl;
    else
        cout<<"Not Found\n";
}

//---------------------------------------------------------
void explainCount(){
    cout<<"\n===== count() =====\n";

    vector<int> v={1,2,2,3,2};

    cout<<"Count of 2 = "<<count(v.begin(),v.end(),2);
    cout<<"\nOutput : 3\n";
}

//---------------------------------------------------------
void explainMaxMin(){
    cout<<"\n===== max_element() =====\n";
    vector<int> v={8,3,15,1};

    cout<<"Maximum = "<<*max_element(v.begin(),v.end());

    cout<<"\n\n===== min_element() =====\n";
    cout<<"Minimum = "<<*min_element(v.begin(),v.end())<<endl;
}

//---------------------------------------------------------
void explainBinarySearch(){
    cout<<"\n===== binary_search() =====\n";

    vector<int> v={5,1,9,3};

    sort(v.begin(),v.end());

    cout<<"Searching 5 : ";

    if(binary_search(v.begin(),v.end(),5))
        cout<<"Present";
    else
        cout<<"Absent";

    cout<<"\n";
}

//---------------------------------------------------------
void explainLowerUpperBound(){
    cout<<"\n===== lower_bound() =====\n";

    vector<int> v={1,2,2,2,5,8};

    auto lb=lower_bound(v.begin(),v.end(),2);
    auto ub=upper_bound(v.begin(),v.end(),2);

    cout<<"lower_bound index : "<<lb-v.begin()<<endl;
    cout<<"upper_bound index : "<<ub-v.begin()<<endl;
}

//---------------------------------------------------------
void explainNextPermutation(){
    cout<<"\n===== next_permutation() =====\n";

    vector<int> v={1,2,3};

    next_permutation(v.begin(),v.end());

    for(int x:v)
        cout<<x<<" ";

    cout<<"\nOutput : 1 3 2\n";
}

//---------------------------------------------------------
void explainRotate(){
    cout<<"\n===== rotate() =====\n";

    vector<int> v={1,2,3,4,5};

    rotate(v.begin(),v.begin()+2,v.end());

    for(int x:v)
        cout<<x<<" ";

    cout<<"\nOutput : 3 4 5 1 2\n";
}

//---------------------------------------------------------
void explainUnique(){
    cout<<"\n===== unique() =====\n";

    vector<int> v={1,1,2,2,3,3};

    auto it=unique(v.begin(),v.end());
    v.erase(it,v.end());

    for(int x:v)
        cout<<x<<" ";

    cout<<"\nOutput : 1 2 3\n";
}

//---------------------------------------------------------
void explainAccumulate(){
    cout<<"\n===== accumulate() =====\n";

    vector<int> v={1,2,3,4};

    cout<<"Sum = "<<accumulate(v.begin(),v.end(),0);

    cout<<"\nOutput : 10\n";
}

//---------------------------------------------------------
void explainSwap(){
    cout<<"\n===== swap() =====\n";

    int a=10,b=20;

    cout<<"Before : "<<a<<" "<<b<<endl;

    swap(a,b);

    cout<<"After  : "<<a<<" "<<b<<endl;
}

//---------------------------------------------------------
void explainFill(){
    cout<<"\n===== fill() =====\n";

    vector<int> v(5);

    fill(v.begin(),v.end(),7);

    for(int x:v)
        cout<<x<<" ";

    cout<<"\nOutput : 7 7 7 7 7\n";
}

//---------------------------------------------------------
int main(){

    explainSort();
    explainReverse();
    explainFind();
    explainCount();
    explainMaxMin();
    explainBinarySearch();
    explainLowerUpperBound();
    explainNextPermutation();
    explainRotate();
    explainUnique();
    explainAccumulate();
    explainSwap();
    explainFill();

    return 0;
}

/*
==========================
Most Important Algorithms
==========================

sort()
stable_sort()
reverse()
find()
count()
binary_search()
lower_bound()
upper_bound()
max_element()
min_element()
next_permutation()
prev_permutation()
rotate()
unique()
accumulate()
fill()
swap()
copy()
equal()
all_of()
any_of()
none_of()
*/


/*
┌──(mahecd "/home/maheshpatil369/Desktop/Learn DSA/DSA.cpp/Learn C++/C++ STL/Algorithms/" && g++          -o      && "/home/maheshpatil369/Desktop/Learn DSA/DSA.cpp/Learn C++/C++ STL/Algorithms/"code

===== sort() =====
Before : 5 2 9 1 
After  : 1 2 5 9 
Output : 1 2 5 9


===== reverse() =====
4 3 2 1 
Output : 4 3 2 1

===== find() =====
30 Found at Index 2

===== count() =====
Count of 2 = 3
Output : 3

===== max_element() =====
Maximum = 15

===== min_element() =====
Minimum = 1

===== binary_search() =====
Searching 5 : Present

===== lower_bound() =====
lower_bound index : 1
upper_bound index : 4

===== next_permutation() =====
1 3 2 
Output : 1 3 2

===== rotate() =====
3 4 5 1 2 
Output : 3 4 5 1 2

===== unique() =====
1 2 3 
Output : 1 2 3

===== accumulate() =====
Sum = 10
Output : 10

===== swap() =====
Before : 10 20
After  : 20 10

===== fill() =====
7 7 7 7 7 
Output : 7 7 7 7 7
                                                                                                                                                                              
┌──(maheshpatil369㉿kali)-[~/…/DSA.cpp/Learn C++/C++ STL/Algorithms]
└─$ 


*/