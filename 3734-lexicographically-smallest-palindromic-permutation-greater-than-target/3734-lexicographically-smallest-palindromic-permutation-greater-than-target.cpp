class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int half = n / 2;

        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;

        int mid = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                if (mid != -1)
                    return "";
                mid = i;
            }
            cnt[i] /= 2;
        }

        vector<int> rem = cnt;

        for (int i = 0; i < half; i++) {
            rem[target[i] - 'a']--;
        }

        auto build = [&](const string& left) {
            string right = left;
            reverse(right.begin(), right.end());

            string ans = left;
            if (mid != -1)
                ans += char('a' + mid);
            ans += right;

            return ans;
        };

        bool possible = true;
        for (int i = 0; i < 26; i++) {
            if (rem[i] < 0)
                possible = false;
        }

        if (possible) {
            string left = target.substr(0, half);
            string candidate = build(left);

            if (candidate > target)
                return candidate;
        }

        for (int i = half - 1; i >= 0; i--) {
            for (int j = target[i] - 'a' + 1; j < 26; j++) {
                vector<int> cur = cnt;

                bool ok = true;

                for (int k = 0; k < i; k++) {
                    int x = target[k] - 'a';
                    cur[x]--;

                    if (cur[x] < 0) {
                        ok = false;
                        break;
                    }
                }

                if (!ok || cur[j] == 0)
                    continue;

                cur[j]--;

                string left = target.substr(0, i);
                left += char('a' + j);

                for (int c = 0; c < 26; c++) {
                    left += string(cur[c], char('a' + c));
                }

                return build(left);
            }
        }

        return "";
    }
};