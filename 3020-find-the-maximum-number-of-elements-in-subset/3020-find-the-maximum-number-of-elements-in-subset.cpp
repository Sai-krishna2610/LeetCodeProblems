class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (int x : nums) cnt[x]++;

        int ans = 1;

        // Handle value 1 separately
        if (cnt.count(1))
            ans = max(ans, cnt[1] - (cnt[1] % 2 == 0));

        for (auto &[start, f] : cnt) {
            if (start == 1) continue;

            long long cur = start;
            int len = 0;

            while (true) {
                if (!cnt.count(cur) || cnt[cur] == 0) {
                    if (len > 0) len--;   // previous level becomes center
                    break;
                }

                if (cnt[cur] == 1) {
                    len++;               // use as center
                    break;
                }

                // cnt[cur] >= 2
                len += 2;

                if (cur > 1000000000LL) break;
                cur = cur * cur;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};