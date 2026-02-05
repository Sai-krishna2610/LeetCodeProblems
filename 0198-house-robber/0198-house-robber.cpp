class Solution {
public:
    //Optimized Approach
    int rob(vector<int>& nums) {
        if (nums.size()==0)
        return 0;
        if (nums.size()==1)
        return nums[0];
        if (nums.size()==2)
        return max(nums[0],nums[1]);
        int firstPart=nums[0];
        int secondPart=max(nums[0],nums[1]);
        int ans=0;
        for(int i=2;i<nums.size();i++)
        {
            ans=max(nums[i]+firstPart,secondPart);
            firstPart=secondPart;
            secondPart=ans;
        }
        return ans;
    }
};