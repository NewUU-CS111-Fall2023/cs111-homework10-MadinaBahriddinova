/*
 USE THIS FILE FOR YOUR TESTS,
 AUTOGRADER WILL NOT EXECUTE THIS FILE.
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include "task_1.cpp"
#include "task_2.cpp"
#include "task_3.cpp"
#include "task_4.cpp"
#include "task_5.cpp"
#include "task_6.cpp"


int main() {
    
    //task1
    std::vector<int> input = {0, 3, 1, 0, 4, 5, 2, 0};
    ListNode* head = new ListNode(input[0]);
    ListNode* current = head;
    for (int i = 1; i < input.size(); ++i) {
        current->next = new ListNode(input[i]);
        current = current->next;
    }

    
    head = mergeZeros(head);

    
    displayLinkedList(head);
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }


 

    return 0;
}
