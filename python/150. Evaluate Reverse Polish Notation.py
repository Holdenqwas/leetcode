from typing import List
from math import floor, ceil

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for token in tokens:
            if token == "+":
                b = stack.pop()
                a = stack.pop()
                stack.append(a + b)
            elif token == "-":
                b = stack.pop()
                a = stack.pop()
                stack.append(a - b)
            elif token == "*":
                b = stack.pop()
                a = stack.pop()
                stack.append(a * b)
            elif token == "/":
                b = stack.pop()
                a = stack.pop()
                val = a / b
                if val <= 0:
                    stack.append(ceil(a / b))
                else:
                    stack.append(floor(a / b))
            else:
                stack.append(int(token))
        return stack.pop()


sol = Solution()

tokens = ["2","1","+","3","*"]
print(sol.evalRPN(tokens), 9)

tokens = ["4","13","5","/","+"]
print(sol.evalRPN(tokens), 6)

tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
print(sol.evalRPN(tokens), 22)
