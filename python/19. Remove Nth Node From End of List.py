from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head: return

        mem = {}
        position = 0

        while head:
            position += 1
            mem[position] = head
            head = head.next
        
        length = len(mem)

        if length == 1:
            return None
        elif n == 1:
            mem[length - 1].next = None
            return mem[1]
        elif n == length:
            return mem[2]
        
        mem[position - n].next = mem[position - n + 2]
        return mem[1]


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
print_val(sol.removeNthFromEnd(head, 2))

items = [1]
head = generate_linked_list(items)
print_val(sol.removeNthFromEnd(head, 1))

items = [1,2]
head = generate_linked_list(items)
print_val(sol.removeNthFromEnd(head, 1))

