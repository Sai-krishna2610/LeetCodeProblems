class Solution {
public:

    bool check(string &s, int index, int balance,
               vector<vector<int>>& dp)
    {
        if (balance < 0)
            return false;

        if (index == s.size())
            return balance == 0;

        if (dp[index][balance] != -1)
            return dp[index][balance];

        if (s[index] == '(')
        {
            return dp[index][balance] =
                check(s, index + 1, balance + 1, dp);
        }

        if (s[index] == ')')
        {
            return dp[index][balance] =
                check(s, index + 1, balance - 1, dp);
        }

        // '*'
        return dp[index][balance] =
            check(s, index + 1, balance + 1, dp) ||
            check(s, index + 1, balance - 1, dp) ||
            check(s, index + 1, balance, dp);
    }

    bool checkValidString(string s)
    {
        vector<vector<int>> dp(
            s.size(),
            vector<int>(s.size() + 1, -1)
        );

        return check(s, 0, 0, dp);
    }
};