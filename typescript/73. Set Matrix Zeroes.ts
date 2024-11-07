function printMatrix(matrix: number[][]): void {
    for (let i = 0; i < matrix.length; i++) {
        const row = matrix[i];
        console.log(row);
    }
}

function setUndef(matrix: number[][], i: number, j: number): void{
    matrix[i] = Array(matrix[0].length).fill(0);

    for (let x = 0; x < matrix.length; x++) {
        matrix[x][j] = 0;
    }
}

function recursiveFill(matrix: number[][], is: number, js: number, isInit: boolean = false): void{
    let i: number = -1, j: number = -1;
    let element = -1;
    for (i = is; i < matrix.length; i++) {
        for (j = js; j < matrix[0].length; j++) {
            if (i == is && j == js && !isInit) continue;
            element = matrix[i][j];
            if (element == 0){
                recursiveFill(matrix, i, j);
                break;
            }
        }
        js=0;
        if (element == 0) break;
    }
    if (element == 0) setUndef(matrix, i, j);
}
/**
 Do not return anything, modify matrix in-place instead.
 */
 function setZeroes(matrix: number[][]): void {
    recursiveFill(matrix, 0, 0, true);
 };


let matrix = [[1,1,1],[1,0,1],[1,1,1]];
setZeroes(matrix);
printMatrix(matrix);
console.log("=============");
printMatrix([[1,0,1],[0,0,0],[1,0,1]]);
console.log("");

matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]];
printMatrix(matrix);
console.log("=============");
setZeroes(matrix);
printMatrix(matrix);
console.log("=============");
printMatrix([[0,0,0,0],[0,4,5,0],[0,3,1,0]]);
console.log("");

matrix = [[1,2,3,4],[5,0,7,8],[0,10,11,12],[13,14,15,0]];
printMatrix(matrix);
console.log("=============");
setZeroes(matrix);
printMatrix(matrix);
console.log("=============");
printMatrix([[0,0,3,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]);