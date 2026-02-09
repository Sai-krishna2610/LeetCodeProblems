/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    /**
 * @param {number} n
 * @return {string[]}
 */
    const ans = [];
    const parenthesis = (left, right, res) => {
        if (left + right === 2 * n) {
            ans.push(res);
            return;
        }
        if (left < n) {
            parenthesis(left + 1, right, res + '(');
        }
        if (right < left) {
            parenthesis(left, right + 1, res + ')');
        }
    };
    parenthesis(0, 0, "");
    return ans;
};