class Solution {
public:
    int climbRecur( vector<int>& costs,int n, vector<int>&dp)
    {
        if(n==0)
        {
            return 0;
        }
        if(dp[n-1]!=-1)
        {
            return dp[n-1];
        }
        int one = INT_MAX;
        int two = INT_MAX;
        int three = INT_MAX;

        if(n >= 1)
            one = climbRecur(costs, n-1,dp) + costs[n-1] + 1;

        if(n >= 2)
            two = climbRecur(costs, n-2, dp) + costs[n-1] + 4;

        if(n >= 3)
            three = climbRecur(costs, n-3, dp) + costs[n-1] + 9;

        return dp[n-1]=min(one, min(two, three));
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,-1);
        return climbRecur(costs,n,dp);
    }
};