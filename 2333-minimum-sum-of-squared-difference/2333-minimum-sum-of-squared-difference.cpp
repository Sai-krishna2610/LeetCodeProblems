class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<long long> diff(n);
        long long maxDiff = 0, total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
            total += diff[i];
        }

        if (total <= k)
            return 0;

        long long low = 0, high = maxDiff;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long needed = 0;

            for (long long d : diff) {
                if (d > mid)
                    needed += d - mid;

                if (needed > k)
                    break;
            }

            if (needed <= k)
                high = mid;
            else
                low = mid + 1;
        }

        long long level = low;
        long long used = 0, ans = 0;

        for (long long d : diff) {
            if (d > level)
                used += d - level;

            long long reduced = min(d, level);
            ans += reduced * reduced;
        }

        long long remaining = k - used;
        ans -= remaining * (2 * level - 1);

        return ans;
    }
};
