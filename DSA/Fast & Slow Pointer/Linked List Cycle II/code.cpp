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

ListNode* detectCycle(ListNode* head) {

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {

            ListNode* ptr = head;

            while (ptr != slow) {
                ptr = ptr->next;
                slow = slow->next;
            }

            return ptr;
        }
    }

    return NULL;
}

int main() {

    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(-4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    n4->next = n2;

    ListNode* ans = detectCycle(n1);

    if (ans != NULL)
        cout << "Cycle starts at node: " << ans->val << endl;
    else
        cout << "No Cycle";

    return 0;
}




/*
https://leetcode.com/problems/linked-list-cycle-ii/description/


┌──(mahecd "/home/maheshpatil369/Desktop/Learn DSA/DSA.cpp/DSA/Fast & Slow Pointer/Linked List Cycle II/" && g++ code.cpp -o      && "/home/maheshpatil369/Desktop/Learn DSA/DSA.cpp/DSA/Fast & Slow Pointer/Linked List Cycle II/"code
Cycle starts at node: 2
                          
*/