#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//optimized approach
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n <= 1)
        {
            return 0;
        }
        vector<int>dp(3,0);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[2] = min(cost[i - 1] + dp[1],
                           cost[i - 2] + dp[0]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[1];
    }
};
