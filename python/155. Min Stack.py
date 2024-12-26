# https://leetcode.com/problems/min-stack/description/?envType=study-plan-v2&envId=top-interview-150

class MinStack:
    def __init__(self):
        self.stack = []
        self.min_value_arr = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        if self.min_value_arr:
           self.min_value_arr.append(min(val, self.min_value_arr[-1]))
        else:
            self.min_value_arr.append(val)

    def pop(self) -> None:
        self.stack.pop()
        self.min_value_arr.pop()


    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min_value_arr[-1]
        


# Your MinStack object will be instantiated and called as such:
obj = MinStack()
obj.push(-2)
obj.push(0)
obj.push(-3)
print(obj.getMin())
obj.pop()
print(obj.top())
print(obj.getMin())