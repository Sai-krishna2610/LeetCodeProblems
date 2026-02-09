/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    const result = [];
    const current = [];
    const generate = (index) => {
        if (index === nums.length) {
            result.push([...current]); 
            return;
        }
        generate(index + 1);
        current.push(nums[index]);
        generate(index + 1);
        current.pop();
    };
    generate(0);
    return result;
};