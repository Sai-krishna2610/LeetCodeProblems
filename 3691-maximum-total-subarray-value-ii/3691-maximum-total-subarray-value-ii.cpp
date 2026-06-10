class Solution {
public:
    using ll = long long;

    struct Node {
        ll val;
        int l, r;

        bool operator<(const Node& other) const {
            return val < other.val;
        }
    };

    vector<vector<int>> stMax, stMin;
    vector<int> lg;

    ll getValue(int l, int r) {
        int len = r - l + 1;
        int k = lg[len];

        int mx = max(stMax[k][l],
                     stMax[k][r - (1 << k) + 1]);

        int mn = min(stMin[k][l],
                     stMin[k][r - (1 << k) + 1]);

        return (ll)mx - mn;
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        lg.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        int LOG = lg[n] + 1;

        stMax.assign(LOG, vector<int>(n));
        stMin.assign(LOG, vector<int>(n));

        for (int i = 0; i < n; i++) {
            stMax[0][i] = nums[i];
            stMin[0][i] = nums[i];
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                stMax[j][i] =
                    max(stMax[j - 1][i],
                        stMax[j - 1][i + (1 << (j - 1))]);

                stMin[j][i] =
                    min(stMin[j - 1][i],
                        stMin[j - 1][i + (1 << (j - 1))]);
            }
        }

        priority_queue<Node> pq;

        for (int l = 0; l < n; l++) {
            pq.push({getValue(l, n - 1), l, n - 1});
        }

        ll ans = 0;

        while (k--) {
            auto [val, l, r] = pq.top();
            pq.pop();

            ans += val;

            if (r > l) {
                pq.push({
                    getValue(l, r - 1),
                    l,
                    r - 1
                });
            }
        }

        return ans;
    }
};