from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        less = []
        greater = []
        dumb = ListNode(0)

        while head:
            if head.val < x:
                less.append(head)
            else:
                greater.append(head)
            head = head.next

        head = dumb
        for node in less:
            head.next = node
            head = node
        
        for node in greater:
            head.next = node
            head = node
        
        head.next = None
        return dumb.next


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

items = [1,4,3,2,5,2]
head = generate_linked_list(items)
print_val(sol.partition(head, 3))

items = [2,1]
head = generate_linked_list(items)
print_val(sol.partition(head, 2))

items = []
head = generate_linked_list(items)
print_val(sol.partition(head, 1))

items = [1,1]
head = generate_linked_list(items)
print_val(sol.partition(head, 3))

items = [1,2]
head = generate_linked_list(items)
print_val(sol.partition(head, 0))

items = [1,8,2]
head = generate_linked_list(items)
print_val(sol.partition(head, 3))

items = [1]
head = generate_linked_list(items)
print_val(sol.partition(head, 9))
