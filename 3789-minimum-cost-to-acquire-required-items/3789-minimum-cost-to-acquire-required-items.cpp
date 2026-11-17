class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        int commonCount = min(need1, need2);
        long long ans = commonCount * min((long long)costBoth, (long long)cost1 + cost2);

        if (need1 > need2) {
            ans += 1LL * (need1 - need2) * min(cost1, costBoth);
        }
        if (need2 > need1) {
            ans += 1LL * (need2 - need1) * min(cost2, costBoth);
        }

        return ans;
    }
};