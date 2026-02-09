class Solution {
public:
    void generate(vector<vector<int>> &result,vector<int>&current,int index,int n,vector<int>& nums)
    {
        if(index==n)
        {
            result.push_back(current);
            return;
        }
        generate(result,current,index+1,n,nums);
        current.push_back(nums[index]);
        generate(result,current,index+1,n,nums);
        current.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        generate(result,current,0,nums.size(),nums);
        return result;
    }
};