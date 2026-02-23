class Solution {
public:
    int findfirstOccurance(vector<int>nums,int target)
    {
        int ans=-1;
        int start=0,end=nums.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)//0 5 2, 3 5 4, 
            {
                ans=mid;
                end=mid-1;
            }
            if (nums[mid]>= target)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;
    }
    int secondOccurance(vector<int>nums,int target)
    {
        int ans=-1;
        int start=0,end=nums.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                start=mid+1;
            }
            if (nums[mid]<= target)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans={-1,-1};
        ans[0]=findfirstOccurance(nums,target);
        if (ans[0]!=-1)
        {
            ans[1]=secondOccurance(nums,target);
        }
        return ans;
    }
};