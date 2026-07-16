#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;

void explainVector(){
    cout<<"=== VECTOR ===\n";
    vector<int> v={10,20,30};
    v.push_back(40);
    v.pop_back();

    cout<<"Range Loop: ";
    for(int x:v) cout<<x<<" ";

    cout<<"\nIterator: ";
    for(auto it=v.begin();it!=v.end();++it) cout<<*it<<" ";

    cout<<"\nIndex: ";
    for(size_t i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<"\n\n";
}

void explainPair(){
    cout<<"=== PAIR ===\n";
    pair<int,string> p={1,"Mahesh"};
    cout<<p.first<<" "<<p.second<<"\n\n";
}

void explainDeque(){
    cout<<"=== DEQUE ===\n";
    deque<int> dq={10,20};
    dq.push_front(5);
    dq.push_back(30);
    for(int x:dq) cout<<x<<" ";
    cout<<"\n\n";
}

void explainList(){
    cout<<"=== LIST ===\n";
    list<int> l={10,20,30};
    l.push_front(5);
    l.push_back(40);
    for(int x:l) cout<<x<<" ";
    cout<<"\n\n";
}

void explainStack(){
    cout<<"=== STACK ===\n";
    stack<int> st;
    st.push(10); st.push(20); st.push(30);
    while(!st.empty()){ cout<<st.top()<<" "; st.pop(); }
    cout<<"\n\n";
}

void explainQueue(){
    cout<<"=== QUEUE ===\n";
    queue<int> q;
    q.push(10); q.push(20); q.push(30);
    while(!q.empty()){ cout<<q.front()<<" "; q.pop(); }
    cout<<"\n\n";
}

void explainPriorityQueue(){
    cout<<"=== PRIORITY_QUEUE ===\n";
    priority_queue<int> pq;
    pq.push(5); pq.push(2); pq.push(10);
    while(!pq.empty()){ cout<<pq.top()<<" "; pq.pop(); }
    cout<<"\n\n";
}

void explainSet(){
    cout<<"=== SET ===\n";
    set<int> s={5,1,5,3};
    for(int x:s) cout<<x<<" ";
    cout<<"\nCount(5): "<<s.count(5)<<"\n\n";
}

void explainMultiSet(){
    cout<<"=== MULTISET ===\n";
    multiset<int> ms;
    ms.insert(1); ms.insert(1); ms.insert(1);
    cout<<"Original: ";
    for(int x:ms) cout<<x<<" ";
    cout<<"\nCount: "<<ms.count(1);
    ms.erase(ms.find(1));
    cout<<"\nAfter erase(find): ";
    for(int x:ms) cout<<x<<" ";
    cout<<"\n\n";
}

void explainUnorderedSet(){
    cout<<"=== UNORDERED_SET ===\n";
    unordered_set<int> us={5,1,9,5};
    for(int x:us) cout<<x<<" ";
    cout<<"\n\n";
}

void explainMap(){
    cout<<"=== MAP ===\n";
    map<string,int> mp;
    mp["Math"]=90;
    mp["Science"]=80;
    for(auto x:mp) cout<<x.first<<" -> "<<x.second<<"\n";
    cout<<"\n";
}

void explainUnorderedMap(){
    cout<<"=== UNORDERED_MAP ===\n";
    unordered_map<string,int> mp;
    mp["A"]=10; mp["B"]=20;
    for(auto x:mp) cout<<x.first<<" -> "<<x.second<<"\n";
    cout<<"\n";
}

int main(){
    explainVector();
    explainPair();
    explainDeque();
    explainList();
    explainStack();
    explainQueue();
    explainPriorityQueue();
    explainSet();
    explainMultiSet();
    explainUnorderedSet();
    explainMap();
    explainUnorderedMap();
    return 0;
}


/*
──(mahecd "/home/maheshpatil369/Desktop/Learn DSA/DSA.cpp/Learn C++/C++ STL/Container/" && g++ code.cpp -o code && "/home/maheshpatil369/Desktop/Learn DSA/DSA.cpp/Learn C++/C++ STL/Container/"code
=== VECTOR ===
Range Loop: 10 20 30 
Iterator: 10 20 30 
Index: 10 20 30 

=== PAIR ===
1 Mahesh

=== DEQUE ===
5 10 20 30 

=== LIST ===
5 10 20 30 40 

=== STACK ===
30 20 10 

=== QUEUE ===
10 20 30 

=== PRIORITY_QUEUE ===
10 5 2 

=== SET ===
1 3 5 
Count(5): 1

=== MULTISET ===
Original: 1 1 1 
Count: 3
After erase(find): 1 1 

=== UNORDERED_SET ===
9 1 5 

=== MAP ===
Math -> 90
Science -> 80

=== UNORDERED_MAP ===
B -> 20
A -> 10

                                                                             
┌──(maheshpatil369㉿kali)-[~/…/DSA.cpp/Learn C++/C++ STL/Container]
└─$ 
*/