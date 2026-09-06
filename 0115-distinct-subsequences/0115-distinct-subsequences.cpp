class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        return solve(s,t,0,0,dp);
    }


    private:
    int solve(string& s, string& t, int i, int j, vector<vector<int>>&dp)
    {
        if(j==t.length())
        return 1;
        if(i==s.length())
        return 0;

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==t[j])
        {
            int pick=solve(s,t,i+1,j+1,dp);
            int skip=solve(s,t,i+1,j,dp);
            return dp[i][j]= pick+skip;
        }
        int skip=solve(s,t,i+1,j,dp);
        return dp[i][j]=skip;
    }
};