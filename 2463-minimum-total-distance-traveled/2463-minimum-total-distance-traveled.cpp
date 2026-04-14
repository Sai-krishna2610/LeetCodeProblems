class Solution {
public:
    long long calc(vector<int>&robot,vector<vector<int>>&factory,int r_ind, int f_ind, vector<vector<long long>>& dp) {

        int r = robot.size(), f = factory.size();

        if (r_ind == r) return 0;
        if (f_ind == f) return 1e18;
        if (dp[r_ind][f_ind] != -1) return dp[r_ind][f_ind];

        long long ans = 1e18;
        int limit = factory[f_ind][1];
        int pos = factory[f_ind][0];

        long long cost = 0;

        for (int i = 0; i <= limit && (r_ind + i) <= r; i++) {

            if (i > 0) {
                cost += abs(pos - robot[r_ind + i - 1]);
            }

            ans = min(ans, cost + calc(robot, factory, r_ind + i, f_ind + 1, dp));
        }

        return dp[r_ind][f_ind] = ans;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());

        int r=robot.size(),f=factory.size();
        vector<vector<long long>>dp(r+1,vector<long long>(f+1,-1));
        return calc(robot,factory,0,0,dp);
    }
};