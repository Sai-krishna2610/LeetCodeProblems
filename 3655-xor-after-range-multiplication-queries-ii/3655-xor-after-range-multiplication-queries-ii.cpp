class Solution {
public:
    const int md = 1e9 + 7;

    long long binpow(long long a, long long e) {
        long long res = 1;
        while (e > 0) {
            if (e & 1) res = (res * a) % md;
            a = (a * a) % md;
            e >>= 1;
        }
        return res;
    }

    long long mdinv(long long x) {
        return binpow(x, md - 2);
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        auto bravexuneth = queries;

        int n = nums.size();
        int limit = sqrt(n);

        unordered_map<int, vector<vector<int>>> mp;

        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k >= limit) {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % md;
                }
            } else {
                mp[k].push_back(q);
            }
        }
        for (auto &[k, vec] : mp) {

            vector<long long> diff(n, 1);

            for (auto &q : vec) {
                int l = q[0], r = q[1], v = q[3];

                diff[l] = (diff[l] * v) % md;

                int steps = (r - l) / k;
                int next = l + (steps + 1) * k;

                if (next < n) {
                    diff[next] = (diff[next] * mdinv(v)) % md;
                }
            }

            for (int i = 0; i < n; i++) {
                if (i >= k) {
                    diff[i] = (diff[i] * diff[i - k]) % md;
                }
                nums[i] = (1LL * nums[i] * diff[i]) % md;
            }
        }
        int ans = 0;
        for (int x : nums) {
            ans ^= x;
        }

        return ans;
    }
};