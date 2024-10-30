function hasRepitition(arr) {
    const set = new Set(arr);
    return set.size != arr.length;
}
function validRow(board) {
    let arr = [];
    for (let i = 0; i < 9; i++) {
        for (let j = 0; j < 9; j++) {
            if (board[i][j] !== ".")
                arr.push(board[i][j]);
        }
        if (hasRepitition(arr))
            return false;
        arr = [];
    }
    console.log("validRow");
    return true;
}
function validColumn(board) {
    let arr = [];
    for (let i = 0; i < 9; i++) {
        for (let j = 0; j < 9; j++) {
            if (board[j][i] !== ".")
                arr.push(board[j][i]);
        }
        if (hasRepitition(arr))
            return false;
        arr = [];
    }
    console.log("validColumn");
    return true;
}
function validBoxes(board) {
    let arr = [];
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            for (let x = i * 3; x < i * 3 + 3; x++) {
                for (let y = j * 3; y < j * 3 + 3; y++) {
                    if (board[x][y] !== ".")
                        arr.push(board[x][y]);
                }
            }
            if (hasRepitition(arr))
                return false;
            arr = [];
        }
    }
    console.log("validBoxes");
    return true;
}
function isValidSudoku(board) {
    if (!validRow(board) || !validColumn(board) || !validBoxes(board))
        return false;
    return true;
}
;
let board = [["5", "3", ".", ".", "7", ".", ".", ".", "."],
    ["6", ".", ".", "1", "9", "5", ".", ".", "."],
    [".", "9", "8", ".", ".", ".", ".", "6", "."],
    ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
    ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
    ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
    [".", "6", ".", ".", ".", ".", "2", "8", "."],
    [".", ".", ".", "4", "1", "9", ".", ".", "5"],
    [".", ".", ".", ".", "8", ".", ".", "7", "9"]];
console.log(isValidSudoku(board));
board =
    [["8", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        [".", ".", ".", ".", "8", ".", ".", "7", "9"]];
console.log(isValidSudoku(board));
