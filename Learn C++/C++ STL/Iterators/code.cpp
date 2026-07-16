#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;

//---------------------------------------------------------
void explainBeginEnd() {
    cout << "\n===== begin() & end() =====\n";

    vector<int> v = {10,20,30,40};

    cout << "Using Iterator : ";

    for(auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";

    cout << "\nOutput : 10 20 30 40\n";
}

//---------------------------------------------------------
void explainReverseIterator() {
    cout << "\n===== rbegin() & rend() =====\n";

    vector<int> v = {10,20,30,40};

    cout << "Reverse : ";

    for(auto it = v.rbegin(); it != v.rend(); ++it)
        cout << *it << " ";

    cout << "\nOutput : 40 30 20 10\n";
}

//---------------------------------------------------------
void explainIteratorOperations() {
    cout << "\n===== Iterator Operations =====\n";

    vector<int> v = {100,200,300,400};

    auto it = v.begin();

    cout << "*it = " << *it << endl;

    ++it;
    cout << "After ++it : " << *it << endl;

    --it;
    cout << "After --it : " << *it << endl;

    it += 2;
    cout << "After it+=2 : " << *it << endl;
}

//---------------------------------------------------------
void explainNextPrev() {
    cout << "\n===== next() & prev() =====\n";

    vector<int> v = {1,2,3,4,5};

    auto it = v.begin();

    cout << "next(begin,2) : " << *next(it,2) << endl;
    cout << "prev(end,2)   : " << *prev(v.end(),2) << endl;
}

//---------------------------------------------------------
void explainAdvance() {
    cout << "\n===== advance() =====\n";

    list<int> l = {10,20,30,40,50};

    auto it = l.begin();

    advance(it,3);

    cout << "After advance(3) : " << *it << endl;
}

//---------------------------------------------------------
void explainDistance() {
    cout << "\n===== distance() =====\n";

    vector<int> v = {10,20,30,40,50};

    auto first = v.begin();
    auto last  = v.end();

    cout << "Distance = " << distance(first,last) << endl;
    cout << "Output : 5\n";
}

//---------------------------------------------------------
void explainFindIterator() {
    cout << "\n===== Iterator with find() =====\n";

    vector<int> v = {5,10,15,20};

    auto it = find(v.begin(),v.end(),15);

    if(it != v.end()){
        cout << "Found : " << *it << endl;
        cout << "Index : " << it-v.begin() << endl;
    }
}

//---------------------------------------------------------
void explainSetIterator() {
    cout << "\n===== Iterator with set =====\n";

    set<int> s = {5,1,8,3};

    for(auto it=s.begin(); it!=s.end(); ++it)
        cout << *it << " ";

    cout << "\nOutput : 1 3 5 8\n";
}

//---------------------------------------------------------
void explainMapIterator() {
    cout << "\n===== Iterator with map =====\n";

    map<string,int> mp;

    mp["Math"]=90;
    mp["Science"]=80;
    mp["English"]=70;

    for(auto it=mp.begin(); it!=mp.end(); ++it){
        cout << it->first << " -> " << it->second << endl;
    }
}

//---------------------------------------------------------
void explainConstIterator() {
    cout << "\n===== const_iterator =====\n";

    vector<int> v = {10,20,30};

    vector<int>::const_iterator it;

    for(it=v.begin(); it!=v.end(); ++it)
        cout << *it << " ";

    cout << "\n(Output cannot be modified through const_iterator)\n";
}

//---------------------------------------------------------
void explainAutoIterator() {
    cout << "\n===== auto Iterator =====\n";

    vector<int> v = {1,2,3};

    for(auto it=v.begin(); it!=v.end(); ++it)
        cout << *it << " ";

    cout << "\n";
}

//---------------------------------------------------------
void explainRangeLoop() {
    cout << "\n===== Range-based Loop =====\n";

    vector<int> v = {10,20,30};

    for(auto x : v)
        cout << x << " ";

    cout << "\n";
}

//---------------------------------------------------------
int main() {

    explainBeginEnd();
    explainReverseIterator();
    explainIteratorOperations();
    explainNextPrev();
    explainAdvance();
    explainDistance();
    explainFindIterator();
    explainSetIterator();
    explainMapIterator();
    explainConstIterator();
    explainAutoIterator();
    explainRangeLoop();

    return 0;
}

/*
──(mahecd "/home/maheshpatil369/Desktop/Learn DSA/DSA.cpp/Learn C++/C++ STL/" && g++                                     -o                                 && "/home/maheshpatil369/Desktop/Learn DSA/DSA.cpp/Learn C++/C++ STL/

===== begin() & end() =====
Using Iterator : 10 20 30 40 
Output : 10 20 30 40

===== rbegin() & rend() =====
Reverse : 40 30 20 10 
Output : 40 30 20 10

===== Iterator Operations =====
*it = 100
After ++it : 200
After --it : 100
After it+=2 : 300

===== next() & prev() =====
next(begin,2) : 3
prev(end,2)   : 4

===== advance() =====
After advance(3) : 40

===== distance() =====
Distance = 5
Output : 5

===== Iterator with find() =====
Found : 15
Index : 2

===== Iterator with set =====
1 3 5 8 
Output : 1 3 5 8

===== Iterator with map =====
English -> 70
Math -> 90
Science -> 80

===== const_iterator =====
10 20 30 
(Output cannot be modified through const_iterator)

===== auto Iterator =====
1 2 3 

===== Range-based Loop =====
10 20 30 
                                                                                                                                                                              
┌──(maheshpatil369㉿kali)-[~/…/Learn DSA/DSA.cpp/Learn C++/C++ STL]
└─$ 
*/
