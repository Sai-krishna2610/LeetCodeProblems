class Solution {
public:
    vector<string> maxNumOfSubstrings(string str) {
        int len = str.size();

        vector<int> firstPos(26, -1);
        vector<int> lastPos(26, 0);
        vector<bool> valid(26, true);

        vector<string> ans;

        for(int i = 0; i < len; i++) {
            int ch = str[i] - 'a';

            if(firstPos[ch] == -1) {
                firstPos[ch] = i;
            }
            lastPos[ch] = i;
        }

        for(int ch = 0; ch < 26; ch++) {
            if(firstPos[ch] == -1) continue;

            for(int j = firstPos[ch]; j <= lastPos[ch]; j++) {
                int curr = str[j] - 'a';

                if(firstPos[curr] < firstPos[ch]) {
                    valid[ch] = false;
                    break;
                }

                lastPos[ch] = max(lastPos[ch], lastPos[curr]);
            }
        }

        int previousStart = INT_MAX;

        for(int i = len - 1; i >= 0; i--) {
            int ch = str[i] - 'a';

            if(!valid[ch]) continue;

            if(i == firstPos[ch] && lastPos[ch] < previousStart) {
                ans.push_back(str.substr(i, lastPos[ch] - i + 1));
                previousStart = i;
            }
        }

        return ans;
    }
};