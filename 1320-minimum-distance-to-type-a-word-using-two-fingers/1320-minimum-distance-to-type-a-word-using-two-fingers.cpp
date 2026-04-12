class Solution {
public:
    int dp[301][27][27];

    pair<int,int> getCoord(int ch) {
        return {ch / 6, ch % 6};
    }

    int dist(int a, int b) {
        if (a == 26) return 0;
        auto [x1, y1] = getCoord(a);
        auto [x2, y2] = getCoord(b);
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(string &word, int i, int f1, int f2) {
        if (i == word.size()) return 0;

        if (dp[i][f1][f2] != -1) return dp[i][f1][f2];

        int curr = word[i] - 'A';

        int useF1 = dist(f1, curr) + solve(word, i + 1, curr, f2);
        int useF2 = dist(f2, curr) + solve(word, i + 1, f1, curr);

        return dp[i][f1][f2] = min(useF1, useF2);
    }

    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return solve(word, 0, 26, 26);
    }
};