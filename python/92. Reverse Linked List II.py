from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseBetween(
        self, head: Optional[ListNode], left: int, right: int
    ) -> Optional[ListNode]:
        if left == right: return head
        start_is_end = False
        original_head = head
        reversed_values = []
        i = 1
        while i + 1 < left:
            i += 1
            head = head.next
        
        left_point = head
        if i != left:
            head = head.next
        else:
            start_is_end = True
            i-=1

        while i < right:
            i += 1
            reversed_values.append(head)
            head = head.next

        if start_is_end:
            left_point = reversed_values.pop()
            original_head = left_point

        for node in reversed(reversed_values):
           left_point.next = node
           left_point = node

        left_point.next = head

        return original_head
        

def generate_linked_list(arr):
    new_items = [ListNode(item) for item in arr]
    for i, item in enumerate(new_items):
        if i != len(items) - 1:
            item.next = new_items[i + 1]

    return new_items[0] if new_items else None


def print_val(head: ListNode):
    while head:
        print(head.val, end=" -> ")
        head = head.next
    print()


sol = Solution()

items = [1, 2, 3, 4, 5]
head = generate_linked_list(items)
print_val(sol.reverseBetween(head, 2, 4))

items = [5]
head = generate_linked_list(items)
print_val(sol.reverseBetween(head, 1, 1))

items = [3,5]
head = generate_linked_list(items)
print_val(sol.reverseBetween(head, 1, 2))
