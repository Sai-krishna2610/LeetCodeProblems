class NumArray {
public:
    vector<int> ans;
    NumArray(vector<int>& nums) {
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            ans.push_back(ans.back()+nums[i]);
        }
    }
    
    int sumRange(int left, int right) {

        if(left==0) return ans[right];
        return ans[right]-ans[left-1];
    }
};