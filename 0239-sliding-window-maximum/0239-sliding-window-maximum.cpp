class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>d;// to store index of maximum to minimum in that k sized window
        vector<int>ans; // to store ans
        for(int i=0;i<k;i++) // creating first window of size K
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
        ans.push_back(nums[d.front()]); // storing first maximum value in first window
        for(int i=k;i<nums.size();i++)
        {
            while(!d.empty() && nums[i]>nums[d.back()]) // in current window removing small values lessthan current value 
            {
                d.pop_back();
            }
            d.push_back(i); //So current value can push
            if(d.front()<=i-k) // if deque first value is out of window we remove that value so we can check in current window maximum value
            // to know first value is out of current window or not we store indexes instead of values
            {
                d.pop_front();
            }
            ans.push_back(nums[d.front()]); // pushing maximum value
        }
        return ans;
    }
};