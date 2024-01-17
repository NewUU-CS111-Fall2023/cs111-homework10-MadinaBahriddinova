/*
 * Author:
 * Date:
 * Name:
 */
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def merge_nodes(head):
    current = head
    while current and current.next:
        if current.val == 0 and current.next.val == 0:
            
            sum_val = 0
            temp = current.next.next
            while temp and temp.val != 0:
                sum_val += temp.val
                temp = temp.next
            current.next = ListNode(sum_val, temp)
        else:
            current = current.next

def remove_zeros(head):
    
    dummy = ListNode(0)
    dummy.next = head
    current = dummy
    while current.next:
        if current.next.val == 0:
            current.next = current.next.next
        else:
            current = current.next
    return dummy.next

def display_linked_list(head):
    result = []
    while head:
        result.append(head.val)
        head = head.next
    print(result)

input_list = [0, 3, 1, 0, 4, 5, 2, 0]


head = ListNode(input_list[0])
current = head
for val in input_list[1:]:
    current.next = ListNode(val)
    current = current.next


merge_nodes(head)
head = remove_zeros(head)


display_linked_list(head)
