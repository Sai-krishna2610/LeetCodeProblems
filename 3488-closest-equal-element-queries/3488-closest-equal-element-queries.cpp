class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {
            int ind = queries[i];
            vector<int>& v = mp[nums[ind]];

            if (v.size() < 2) {
                ans.push_back(-1);
                continue;
            }

            int k = lower_bound(v.begin(), v.end(), ind) - v.begin();
            int N = v.size();

            int left = v[(k - 1 + N) % N];
            int right = v[(k + 1) % N];

            int dist1 = abs(ind - left);
            int dist2 = abs(ind - right);

            dist1 = min(dist1, n - dist1);
            dist2 = min(dist2, n - dist2);

            ans.push_back(min(dist1, dist2));
        }

        return ans;
    }
};