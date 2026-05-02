class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> dp(n + 1, 0);
        int count = 0;

        for (int i = 0; i <= n; i++) {
            if (i < 10) {
                // base cases
                if (i == 0 || i == 1 || i == 8) dp[i] = 1;
                else if (i == 2 || i == 5 || i == 6 || i == 9) {
                    dp[i] = 2;
                    count++;
                } else {
                    dp[i] = 0;
                }
            } else {
                int last = i % 10;
                int prev = i / 10;

                if (dp[prev] == 0 || last == 3 || last == 4 || last == 7) {
                    dp[i] = 0;
                } 
                else if (dp[prev] == 1 && (last == 0 || last == 1 || last == 8)) {
                    dp[i] = 1;
                } 
                else {
                    dp[i] = 2;
                    count++;
                }
            }
        }

        return count;
    }
};