/**
 * @param {number[]} nums
 * @return {number}
 */
var longestBalanced = function(nums) {
    let n=nums.length;
    let maxLen=0;
    for(let i=0;i<n;i++)
    {
        let evenSet=new Set();
        let oddSet= new Set();
        for(let j=i;j<n;j++)
        {
            if(nums[j]%2==0)
            evenSet.add(nums[j]);
            else
            oddSet.add(nums[j]);

            if(evenSet.size===oddSet.size)
            maxLen=Math.max(maxLen,j-i+1);
        }
    }
    return maxLen;
};