class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<vector<bool>> palindrome(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++) {
            for (int left = 0; left + len <= n; left++) {

                int right = left + len - 1;

                if (len == 1) {
                    palindrome[left][right] = true;
                }
                else if (len == 2) {
                    palindrome[left][right] =
                        (s[left] == s[right]);
                }
                else {
                    palindrome[left][right] =
                        (s[left] == s[right] &&
                         palindrome[left + 1][right - 1]);
                }
            }
        }

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            dp[i] = dp[i - 1];

            for (int j = 0; j < i; j++) {

                int length = i - j;

                if (length >= k && palindrome[j][i - 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};