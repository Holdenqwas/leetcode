from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dumb = ListNode(0)

        start = dumb
        cur_val = None
        while head:
            while head.next and (head.val == head.next.val or head.val == cur_val):
                cur_val = head.val
                head = head.next
            
            if head.val != cur_val:
                start.next = head
                cur_val = None
                start = head
            head = head.next
        
        start.next = None
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

items = [1,2,3,3,4,4,5]
head = generate_linked_list(items)
print_val(sol.deleteDuplicates(head))

items = [1,1,1,2,3]
head = generate_linked_list(items)
print_val(sol.deleteDuplicates(head))

items = []
head = generate_linked_list(items)
print_val(sol.deleteDuplicates(head))

items = [1,1]
head = generate_linked_list(items)
print_val(sol.deleteDuplicates(head))

items = [1,2,2]
head = generate_linked_list(items)
print_val(sol.deleteDuplicates(head))
