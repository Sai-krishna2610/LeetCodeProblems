class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> temp(nums.begin(),nums.end());
        int maxLength=0;
        
        for(int num:temp)
        {
            if(!temp.count(num-1)){
                int val=num;
                int currentLength=0;
                while(temp.count(val))
                {
                    currentLength++;
                    val++;
                }
                maxLength=max(currentLength,maxLength);
            }

        }
        return maxLength;
    }
};