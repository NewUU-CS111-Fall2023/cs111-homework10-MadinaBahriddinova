/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeNodes(ListNode* start, ListNode* end) {
    int sum = 0;
    ListNode* current = start;
    
    while (current != end) {
        sum += current->val;
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    
    return new ListNode(sum);
}

ListNode* mergeZeros(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* current = dummy;

    while (current->next) {
        if (current->next->val == 0) {
            ListNode* start = current->next;
            while (current->next && current->next->val == 0) {
                current = current->next;
            }
            ListNode* end = current->next;

            ListNode* mergedNode = mergeNodes(start->next, end);
            start->next = mergedNode;
            current = start;
        } else {
            current = current->next;
        }
    }

    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
}

void displayLinkedList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

