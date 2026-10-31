
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        constexpr int MOD = 1'000'000'007;

        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<array<long long, 2>>> dp(
            rows, vector<array<long long, 2>>(cols, {0, 0})
        );

        dp[0][0][0] = 1;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                if (row > 0) {
                    if (grid[row - 1][col] == 0) {
                        dp[row][col][0] =
                            (dp[row - 1][col][0] +
                             dp[row - 1][col][1]) % MOD;
                    } else {
                        dp[row][col][0] = dp[row - 1][col][1];
                    }
                }

                if (col > 0) {
                    if (grid[row][col - 1] == 0) {
                        dp[row][col][1] =
                            (dp[row][col - 1][0] +
                             dp[row][col - 1][1]) % MOD;
                    } else {
                        dp[row][col][1] = dp[row][col - 1][0];
                    }
                }
            }
        }

        return (dp[rows - 1][cols - 1][0] +
                dp[rows - 1][cols - 1][1]) % MOD;
    }
};
