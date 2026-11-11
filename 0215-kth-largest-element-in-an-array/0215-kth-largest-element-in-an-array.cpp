class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0;i<k;i++)
        {
            pq.push(nums[i]);
        }
        while(k<nums.size())
        {
            if(pq.top()<nums[k]){
                pq.pop();
                pq.push(nums[k]);
            }
            k++;
        }
        return pq.top();
    }
};