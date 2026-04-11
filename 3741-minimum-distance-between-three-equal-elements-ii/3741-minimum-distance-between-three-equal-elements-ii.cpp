class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for (auto &it : mp) {
            auto &v = it.second;

            if (v.size() < 3) continue;

            for (int i = 0; i + 2 < v.size(); i++) {
                int p = v[i];
                int r = v[i + 2];

                ans = min(ans, 2 * (r - p));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};