/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var findTheWinner = function(n, k) {

    function winner(n, k) {
        if (n === 1) return 0;                 
        return (winner(n - 1, k) + k) % n;     
    }

    return winner(n, k) + 1; 
};