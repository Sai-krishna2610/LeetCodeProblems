class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ones=0,twos=0,zeroes=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            zeroes++;
            else if(nums[i]==1)
            ones++;
            else if(nums[i]==2)
            twos++;   
        }
        int i=0;
        while(zeroes-- && i<nums.size())
        {
            nums[i]=0;
            i++;
        }
        while(ones-- && i<nums.size())
        {
            nums[i]=1;
            i++;
        }
        while(twos-- && i<nums.size())
        {
            nums[i]=2;
            i++;
        }
    }
};