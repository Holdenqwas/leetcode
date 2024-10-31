function swap(a: number, b: number, c: number, d: number){

}

/**
 Do not return anything, modify matrix in-place instead.
*/
function rotate(matrix: number[][]): void {
    const n = matrix.length - 1;

    for (let i = 0; i < n / 2; i++){
        for (let j = i; j < n - i; j++) {
            const temp = matrix[i][j];
            matrix[i][j] = matrix[n - j][i];
            matrix[n - j][i] = matrix[n - i][n - j];
            matrix[n - i][n - j] = matrix[j][n - i];
            matrix[j][n - i] = temp;
        }
    }
};

let matrix = [[1,2,3],[4,5,6],[7,8,9]];
rotate(matrix);
console.log(matrix, "[[7,4,1],[8,5,2],[9,6,3]]")

matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]];
rotate(matrix);
console.log(matrix, "[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]")