from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head:
            return
        elif not head.next or k == 0:
            return head
        
        mem = []

        while head:
            mem.append(head)
            head = head.next

        length = len(mem)
        k = k % length

        while k > 0:
            k -= 1
            mem.insert(0, mem[-1])
            mem.pop()

        dumb = ListNode(0)
        head = dumb
        for node in mem:
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

items = [1,2,3,4,5]
head = generate_linked_list(items)
print_val(sol.rotateRight(head, 2))

items = [0,1,2]
head = generate_linked_list(items)
print_val(sol.rotateRight(head, 4))

items = []
head = generate_linked_list(items)
print_val(sol.rotateRight(head, 1))

items = [1,2]
head = generate_linked_list(items)
print_val(sol.rotateRight(head, 0))

items = [1,2]
head = generate_linked_list(items)
print_val(sol.rotateRight(head, 1))

items = [1,2]
head = generate_linked_list(items)
print_val(sol.rotateRight(head, 2))

items = [1]
head = generate_linked_list(items)
print_val(sol.rotateRight(head, 3))
