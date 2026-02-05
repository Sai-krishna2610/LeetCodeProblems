class Solution {
public:
    int robber(vector<int>&nums,int index)
    {
        if(index==0)
        {
            return nums[0];
        }
        if(index==1)
        {
            return max(nums[0],nums[1]);
        }
        return max(nums[index]+robber(nums,index-2),robber(nums,index-1));
    }
    int rob(vector<int>& nums) {
        return robber(nums,nums.size()-1);
    }
};