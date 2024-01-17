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

int main() {
    
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
