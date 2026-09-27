class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;

        string ans = "";

        for (char c : s) {
            mp[c]++;
        }

        vector<pair<char, int>> v(mp.begin(), mp.end());

        sort(v.begin(), v.end(), [](pair<char, int>& a, pair<char, int>& b) {
            if (a.second != b.second)
                return a.second > b.second;

            return a.first < b.first;
        });

        for (auto p : v) {
            while (p.second > 0) {
                ans += p.first;
                p.second--;
            }
        }

        return ans;
    }
};