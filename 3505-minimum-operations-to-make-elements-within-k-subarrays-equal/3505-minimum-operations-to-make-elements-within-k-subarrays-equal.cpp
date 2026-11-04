class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n=nums.size();
        multiset<int>lower,upper;

        long long lowerSum=0;
        long long upperSum=0;

        auto balance=[&]()
        {
            while(lower.size()>upper.size()+1)
            {
                int val= *lower.rbegin();
                lower.erase(prev(lower.end()));
                lowerSum-=val;

                upper.insert(val);
                upperSum+=val;
            }

            while(lower.size()<upper.size())
            {
                int val = *upper.begin();

                upper.erase(upper.begin());
                upperSum -= val;

                lower.insert(val);
                lowerSum += val;
            }
        };

        auto add= [&](int val) {

            if (lower.empty() || val <= *lower.rbegin()) {
                lower.insert(val);
                lowerSum += val;
            }
            else {
                upper.insert(val);
                upperSum += val;
            }

            balance();
        };

        auto remove = [&](int val) {

            auto it = lower.find(val);

            if (it != lower.end()) {
                lower.erase(it);
                lowerSum -= val;
            }
            else {
                it = upper.find(val);
                upper.erase(it);
                upperSum -= val;
            }

            balance();
        };
        vector<long long> cost(n - x + 1);

        for (int i = 0; i < n; i++) {

            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {

                long long median = *lower.rbegin();

                long long leftCost =
                    median * lower.size() - lowerSum;

                long long rightCost =
                    upperSum - median * upper.size();

                cost[i - x + 1] = leftCost + rightCost;
            }
        }

        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = n - 1; i >= 0; i--) {

            for (int j = 1; j <= k; j++) {

                long long skip = dp[i + 1][j];

                long long pick = INF;

                if (i + x <= n && dp[i + x][j - 1] != INF) {
                    pick = cost[i] + dp[i + x][j - 1];
                }

                dp[i][j] = min(skip, pick);
            }
        }

        return dp[0][k];

    }
};