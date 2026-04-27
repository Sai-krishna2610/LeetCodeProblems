class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int total=0;
        for(int i=0;i<nums.size();i++)
        {
            total+=nums[i];
        }
        int curValue=0;
        for(int i=0;i<nums.size();i++)
        {
            if(total-nums[i]-curValue==curValue)
            {
                return i;
            }
            curValue+=nums[i];
        }
        return -1;
    }
};