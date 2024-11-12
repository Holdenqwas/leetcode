from typing import List

def printMatrix(board: List[List[int]]) -> None:
    for i in range(len(board)):
        for j in range(len(board[0])):
            print(board[i][j], end=" ")
        print()

class Solution:
    def getCountAliveNeighbors(self, i: int, j: int, board: List[List[int]]) -> int:
        m = len(board) - 1
        n = len(board[0]) - 1
        count = 0

        if i > 0: count += board[i-1][j]
        if i < m: count += board[i+1][j]
        if j > 0: count += board[i][j-1]
        if j < n: count += board[i][j+1]

        if i > 0 and j > 0: count += board[i-1][j-1]
        if i > 0 and j < n: count += board[i-1][j+1]
        if j > 0 and i < m: count += board[i+1][j-1]
        if j < n and i < m: count += board[i+1][j+1]

        return count
    
    def calculateValue(self, ai: int, aj: int, board: List[List[int]]):
        curI = None
        curJ = None
        count = 0

        for i in range(ai, len(board)):
            for j in range(len(board[0])):
                if i==ai and j < aj: continue
                curI, curJ = i, j
                count = self.getCountAliveNeighbors(i, j, board)
                self.calculateValue(i, j+1, board)
                break
            if curI != None: break
        if curI!= None:
            if board[curI][curJ] and count < 2: 
                board[curI][curJ] = 0
            elif board[curI][curJ] and count <= 3: 
                board[curI][curJ] = 1
            elif not board[curI][curJ] and count == 3: 
                board[curI][curJ] = 1
            else:
                board[curI][curJ] = 0

    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        self.calculateValue(0, 0, board)

solution = Solution()
board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
printMatrix(board)
print("Correct answer")
printMatrix([[0,0,0],[1,0,1],[0,1,1],[0,1,0]]) 
print("Solution")
solution.gameOfLife(board)
printMatrix(board)

print()
board = [[1,1],[1,0]]
solution.gameOfLife(board)
printMatrix(board)
