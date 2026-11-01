class Solution {
public:
    int coinsChange(int n, vector<int>& coins, int amount, vector<vector<int>>&dp)
    {
        if(amount==0)
        {
            return 1;
        }
        if(n==0 || amount<0)
        {
            return 0;
        }
        if(dp[n][amount]!=-1)
        {
            return dp[n][amount];
        }
        return dp[n][amount]=coinsChange(n-1, coins, amount, dp)+coinsChange(n, coins, amount-coins[n-1], dp);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        return coinsChange(coins.size(),coins,amount,dp);
    }
};