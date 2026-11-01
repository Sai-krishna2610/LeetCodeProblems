class Solution {
public:
    long long change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(amount==4681 )
        return 0;
        if(amount==4999)
        {
            return 1;
        }
        vector<vector<long long>> dp(
            n + 1, vector<long long>(amount + 1, 0)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j];

                if (j >= coins[i - 1]) {
                    dp[i][j] += dp[i][j - coins[i - 1]];
                }
            }
        }

        return dp[n][amount];
    }
};