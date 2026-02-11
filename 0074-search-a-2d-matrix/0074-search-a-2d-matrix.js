/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    if (!matrix.length || !matrix[0].length) return false;

    let n = matrix[0].length;

    let left = 0, right = matrix.length * n - 1;

    while (left <= right) {
        let mid = Math.floor((left + right) / 2);

        let i = Math.floor(mid / n);
        let j = mid % n;

        if (matrix[i][j] === target) return true;
        else if (matrix[i][j] > target) right = mid - 1;
        else left = mid + 1;
    }

    return false;
};
