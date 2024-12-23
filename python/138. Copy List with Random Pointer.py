# https://leetcode.com/problems/copy-list-with-random-pointer/?envType=study-plan-v2&envId=top-interview-150
from typing import Optional

class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head: return

        mem = {}
        cur_node = head
        while cur_node:
            mem[cur_node] = Node(cur_node.val)
            cur_node = cur_node.next

        cur_node = head
        while cur_node:
            next_val = cur_node.next
            if next_val:
                mem[cur_node].next = mem[cur_node.next]
            random_val = cur_node.random
            if random_val:
                mem[cur_node].random = mem[random_val]
            cur_node = cur_node.next
        
        return mem[head]
    

def generate_linked_list(items) -> Node:
    new_items = [Node(item[0]) for item in items]
    for i, item in enumerate(new_items):
        if i != len(items) - 1:
            item.next = new_items[i+1]
        
        random = items[i][1]
        if random:
            item.random = new_items[random]
    return new_items[0] if new_items else None

def print_val(head: Node):
    while head:
        print(head.val, end=" -> ")
        head = head.next

sol = Solution()
items = [[7, None],[13, 0],[11, 4],[10, 2],[1, 0]]
head = generate_linked_list(items)
hew_head = sol.copyRandomList(head)
print_val(hew_head)

items = [[1,1],[2,1]]
head = generate_linked_list(items)
hew_head = sol.copyRandomList(head)
print_val(hew_head)

items = [[3,None],[3,0],[3,None]]
head = generate_linked_list(items)
hew_head = sol.copyRandomList(head)
print_val(hew_head)
        