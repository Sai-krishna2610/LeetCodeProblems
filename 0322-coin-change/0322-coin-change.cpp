class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
         vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        
         // zero row ko initlize kar do , 1e9
         // zero column ko initlize kar do zero se

         for(int j=0;j<=amount;j++)
         dp[0][j] = 1e9;



         for(int i=0;i<=n;i++){
            dp[i][0] = 0;
         }


         for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(j-coins[i-1]>=0)
                dp[i][j] = min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                else
                dp[i][j] = dp[i-1][j];
            }
         }


         return dp[n][amount]>=1e9 ? -1: dp[n][amount];
    }
};