class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int totalCount = 0;
        long long prefixSum = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int mod = ((prefixSum % k) + k) % k; 
            if (m.count(mod)) {
                totalCount += m[mod];
            }
            m[mod]++;
        }
        return totalCount;
    }
};