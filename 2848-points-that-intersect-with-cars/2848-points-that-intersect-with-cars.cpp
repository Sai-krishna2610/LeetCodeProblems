class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());

        int total=0;
        int start=nums[0][0];
        int end=nums[0][1];

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i][0]<=end)
            {
                end=max(end,nums[i][1]);
            }
            else
            {
                total+=(end-start+1);
                start=nums[i][0];
                end=nums[i][1];
            }
        }
        total+=(end-start+1);
        return total;
    }
};