class Solution {
public:
    long long maxSumTrionic(const vector<int>& nums) {
        const long long NEG_INF = -(1LL << 50);

        long long a = NEG_INF;
        long long b = NEG_INF; 
        long long c = NEG_INF; 
        long long result = NEG_INF;

        long long prev = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            long long curr = nums[i];

            long long na = NEG_INF, nb = NEG_INF, nc = NEG_INF;

            if (curr > prev) {
                na = max(a, prev) + curr;
                if (b != NEG_INF || c != NEG_INF)
                    nc = max(b, c) + curr;
            }
            else if (curr < prev) {
                if (a != NEG_INF || b != NEG_INF)
                    nb = max(a, b) + curr;
            }
            a = na;
            b = nb;
            c = nc;
            result = max(result, c);
            prev = curr;
        }
        return result;
    }
};
