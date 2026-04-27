class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>prefixSum(n);
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }
        vector<int>result;

        for(int q:queries)
        {
            int count=upper_bound(prefixSum.begin(),prefixSum.end(),q)-prefixSum.begin();
            result.push_back(count);
        }

        return result;
    }
};