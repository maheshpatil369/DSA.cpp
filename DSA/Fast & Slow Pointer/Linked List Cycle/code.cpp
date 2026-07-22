#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

bool hasCycle( ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) 
        return true;
    }
    return false;

}

int main () {
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(-4);

    n1->next =n2;
    n2->next =n3;
    n3->next =n4;
// Create a cycle there 
    n4->next = n2;


    if (hasCycle(n1))
    cout << "Cycle found";
    else
    cout << "No cycle";

    return 0;

}




/*
https://leetcode.com/problems/linked-list-cycle/description/


┌──(mahecd "/home/maheshpatil369/Desktop/Learn DSA/DSA.cpp/DSA/Fast & Slow Pointer/Linked List Cycle/" && g++          -o      && "/home/maheshpatil369/Desktop/Learn DSA/DSA.cpp/DSA/Fast & Slow Pointer/Linked List Cycle/"code
Cycle found  
*/