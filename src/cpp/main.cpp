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
    
 //task2
    std::string input = "11101111";
    std::string result = unaryAddition(input);
    std::cout << result << std::endl;

 //task3
    std::string input = "0111c11110";
    std::string result = compareNumbers(input);
    std::cout << result << std::endl;

 //task4
    std::string input = "0111c11110";
    std::string result = multiplyNumbers(input);
    std::cout << result << std::endl;

 //task5
    std::vector<int> numbers = {-5, -17, 7, -4, 3, -2, 4};
    bool result = hasZeroSumTriplet(numbers);
    if (result) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

 //task6
    std::vector<std::vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4;
    int k = 2;
    int result = networkDelayTime(times, n, k);
    std::cout << result << std::endl;

 //task7
    std::vector<int> answers = {1, 1, 2};
    int result = minRabbits(answers);
    std::cout << result << std::endl;

 //task8
    std::vector<int> nums1 = {1, 5, 11, 5};
    std::vector<int> nums2 = {1, 2, 3, 5};
    std::vector<int> nums3 = {12, 2, 31, 0, 5};
    std::cout << std::boolalpha << canPartition(nums1) << std::endl; 
    std::cout << std::boolalpha << canPartition(nums2) << std::endl;  
    std::cout << std::boolalpha << canPartition(nums3) << std::endl;  


 

    return 0;
}
