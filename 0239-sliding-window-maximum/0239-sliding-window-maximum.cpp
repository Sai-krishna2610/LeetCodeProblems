class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>d;
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            if(d.empty())
            {
                d.push_back(i);
            }
            else
            {
                while(!d.empty() && nums[i]>nums[d.back()])
                {
                    d.pop_back();
                }
                d.push_back(i);
            }
        }
        ans.push_back(nums[d.front()]);
        for(int i=k;i<nums.size();i++)
        {
            while(!d.empty() && nums[i]>nums[d.back()])
            {
                d.pop_back();
            }
            d.push_back(i);
            if(d.front()<=i-k)
            {
                d.pop_front();
            }
            ans.push_back(nums[d.front()]);
        }
        return ans;
    }
};