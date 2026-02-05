class Solution {
public:
    int robber(vector<int>&nums,int index,vector<int>&dp)
    {
        if(index==0)
        {
            return nums[0];
        }
        if(index==1)
        {
            return max(nums[0],nums[1]);
        }
        if (dp[index]!=-1)
        return dp[index];
        return dp[index]=max(nums[index]+robber(nums,index-2,dp),robber(nums,index-1,dp));
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return robber(nums,nums.size()-1,dp);
    }
};