class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        int index=1;
        for(int num:nums)
        {
            if(n%index==0)
            {
                ans+=num*num;
            }
            index++;

        }
        return ans;
    }
};