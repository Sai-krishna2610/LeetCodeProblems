class Solution {
public:
    //optimized approach
    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0;  // dp[i-2]
        int prev1 = 0;  // dp[i-1]

        for (int i = start; i <= end; i++) {
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        return max(robLinear(nums, 0, n - 2),robLinear(nums, 1, n - 1)
        );
    }
};
