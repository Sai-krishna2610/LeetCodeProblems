class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];
        vector<int> dp(end - start + 1);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);
        for (int i = 2; i < dp.size(); i++) {
            dp[i] = max(dp[i - 1], nums[start + i] + dp[i - 2]);
        }
        return dp.back();
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        return max(robLinear(nums, 0, n - 2),robLinear(nums, 1, n - 1));
    }
};
