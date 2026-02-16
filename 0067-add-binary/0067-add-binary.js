/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    
        let res = "";
        let carry = 0;
        let i = a.length - 1;
        let j = b.length - 1;

        while (i >= 0 && j >= 0) {
            carry += (a[i--] - '0') + (b[j--] - '0');
            res += (carry % 2);
            carry = Math.floor(carry / 2);
        }

        while (i >= 0) { // for remaining characters in a
            carry += (a[i--] - '0');
            res += (carry % 2);
            carry = Math.floor(carry / 2);
        }

        while (j >= 0) { // for remaining characters in b
            carry += (b[j--] - '0');
            res += (carry % 2);
            carry = Math.floor(carry / 2);
        }

        if (carry) {
            res += '1';
        }

        return res.split('').reverse().join('');
    
};