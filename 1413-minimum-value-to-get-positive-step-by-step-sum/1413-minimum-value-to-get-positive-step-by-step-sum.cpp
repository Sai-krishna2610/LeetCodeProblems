class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans=0;
        int minValue=0;
        int present=0;
        for(int num:nums)
        {
            present+=num;
            if (minValue>present)
            {
                minValue=present;
            }
        }
        if (minValue<0)
        {
            return -minValue+1;
        }
        return 1;
    }
};