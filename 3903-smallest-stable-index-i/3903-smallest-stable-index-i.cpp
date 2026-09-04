class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>suf(n,-1);
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suf[i]=min(suf[i+1],nums[i]);
        }
        int preMax=nums[0];
        for(int i=0;i<n;i++)
        {
            preMax=max(nums[i],preMax);
            if(preMax-suf[i]<=k)
            return i;
        }
        return -1;
    }
};