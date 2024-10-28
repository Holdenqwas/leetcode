enum Direction {
    right = 1,
    down,
    left,
    up
}
function spiralOrder(matrix: number[][]): number[] {
    let limit_r = matrix[0].length;
    let limit_d = matrix.length;
    let limit_l = 0;
    let limit_u = 1;
    let i = 0, j = 0;
    const size = limit_r * limit_d;
    const output: Array<number> = [];

    let direction = Direction.right;

    while (output.length != size) {
        output.push(matrix[i][j]);
        switch (direction) {
            case Direction.right:
                if ((j + 1) < limit_r) j++;
                else {
                    direction = Direction.down;
                    i++;
                    limit_r--;
                }
                break;
            case Direction.down:
                if ((i + 1) < limit_d) i++;
                else {
                    direction = Direction.left;
                    j--;
                    limit_d--;
                }
                break;
            case Direction.left:
                if ((j - 1) >= limit_l) j--;
                else {
                    direction = Direction.up;
                    i--;
                    limit_l++;
                }
                break;
            case Direction.up:
                if ((i - 1) >= limit_u) i--;
                else {
                    direction = Direction.right;
                    j++;
                    limit_u++;
                }
                break;
        }
    }
    return output;
};

let matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
console.log(spiralOrder(matrix));
console.log("[1,2,3,6,9,8,7,4,5] - Correct output");
console.log();

matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]];
console.log(spiralOrder(matrix));
console.log("[1,2,3,4,8,12,11,10,9,5,6,7] - Correct output");
console.log();