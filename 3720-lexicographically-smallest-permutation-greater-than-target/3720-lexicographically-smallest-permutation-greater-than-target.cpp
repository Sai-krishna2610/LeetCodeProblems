class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        int n = s.size();
        int matched = 0;

        while (matched < n && freq[target[matched] - 'a'] > 0) {
            freq[target[matched] - 'a']--;
            matched++;
        }

        if (matched < n) {
            int cur = target[matched] - 'a';

            for (int c = cur + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    string ans = target.substr(0, matched);
                    ans += char('a' + c);
                    freq[c]--;

                    for (int j = 0; j < 26; j++)
                        ans += string(freq[j], char('a' + j));

                    return ans;
                }
            }
        }

        for (int i = matched - 1; i >= 0; i--) {
            freq[target[i] - 'a']++;

            int cur = target[i] - 'a';

            for (int c = cur + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    string ans = target.substr(0, i);
                    ans += char('a' + c);
                    freq[c]--;

                    for (int j = 0; j < 26; j++)
                        ans += string(freq[j], char('a' + j));

                    return ans;
                }
            }
        }

        return "";
    }
};