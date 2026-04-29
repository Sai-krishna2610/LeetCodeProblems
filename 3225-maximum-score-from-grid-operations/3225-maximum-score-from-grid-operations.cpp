using ll = long long;
using vll = std::vector<ll>;

class Solution {
public:
    ll maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return 0;

        vector<vector<vll>> dp(n, vector<vll>(n + 1, vll(n + 1, 0)));
        vector<vll> prefixMax(n + 1, vll(n + 1, 0));
        vector<vll> suffixMax(n + 1, vll(n + 1, 0));
        vector<vll> columnPrefixSum(n, vll(n + 1, 0));

        for (int col = 0; col < n; col++) {
            for (int row = 1; row <= n; row++) {
                columnPrefixSum[col][row] =
                    columnPrefixSum[col][row - 1] + grid[row - 1][col];
            }
        }

        for (int col = 1; col < n; col++) {
            for (int currHeight = 0; currHeight <= n; currHeight++) {
                for (int prevHeight = 0; prevHeight <= n; prevHeight++) {

                    if (currHeight <= prevHeight) {
                        ll gain = columnPrefixSum[col][prevHeight] -
                                  columnPrefixSum[col][currHeight];

                        dp[col][currHeight][prevHeight] = max(
                            dp[col][currHeight][prevHeight],
                            suffixMax[prevHeight][0] + gain
                        );
                    } else {
                        ll gain = columnPrefixSum[col - 1][currHeight] -
                                  columnPrefixSum[col - 1][prevHeight];

                        dp[col][currHeight][prevHeight] = max({
                            dp[col][currHeight][prevHeight],
                            suffixMax[prevHeight][currHeight],
                            prefixMax[prevHeight][currHeight] + gain
                        });
                    }
                }
            }

            for (int currHeight = 0; currHeight <= n; currHeight++) {

                prefixMax[currHeight][0] = dp[col][currHeight][0];

                for (int prevHeight = 1; prevHeight <= n; prevHeight++) {
                    ll penalty = (prevHeight > currHeight)
                        ? (columnPrefixSum[col][prevHeight] -
                           columnPrefixSum[col][currHeight])
                        : 0;

                    prefixMax[currHeight][prevHeight] = max(
                        prefixMax[currHeight][prevHeight - 1],
                        dp[col][currHeight][prevHeight] - penalty
                    );
                }

                suffixMax[currHeight][n] = dp[col][currHeight][n];

                for (int prevHeight = n - 1; prevHeight >= 0; prevHeight--) {
                    suffixMax[currHeight][prevHeight] = max(
                        suffixMax[currHeight][prevHeight + 1],
                        dp[col][currHeight][prevHeight]
                    );
                }
            }
        }

        ll answer = 0;

        for (int prevHeight = 0; prevHeight <= n; prevHeight++) {
            answer = max({
                answer,
                dp[n - 1][n][prevHeight],
                dp[n - 1][0][prevHeight]
            });
        }

        return answer;
    }
};