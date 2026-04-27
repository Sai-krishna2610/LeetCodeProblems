class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int count=0;
        int pos=0;
        for(int i=0;i<nums.size();i++)
        {
            pos+=nums[i];
            if(pos==0){
                count++;
            }
        }
        return count;
    }
};