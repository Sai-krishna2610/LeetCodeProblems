class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        for(auto num:nums)
        {
            sum+=num;
        }
        long long total_sum=n*(n+1)/2;
        return total_sum-sum;
    }
};