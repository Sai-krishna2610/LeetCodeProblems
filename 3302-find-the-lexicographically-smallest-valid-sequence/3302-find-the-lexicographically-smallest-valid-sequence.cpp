class Solution {
public:
    vector<int> validSequence(string source, string target) {
        int len1 = source.size();
        int len2 = target.size();

        vector<int> rightMost(len2, -1);
        int pos = len2 - 1;

        for (int idx = len1 - 1; idx >= 0; --idx) {
            if (pos >= 0 && source[idx] == target[pos]) {
                rightMost[pos] = idx;
                pos--;
            }
        }

        vector<int> result;
        int changed = 0;
        int targetIdx = 0;

        for (int idx = 0; idx < len1; idx++) {
            if (targetIdx == len2) {
                break;
            }

            if (source[idx] == target[targetIdx] ||
                (changed == 0 &&
                 (targetIdx == len2 - 1 || idx < rightMost[targetIdx + 1]))) {

                if (source[idx] != target[targetIdx]) {
                    changed = 1;
                }

                result.push_back(idx);
                targetIdx++;
            }
        }

        if (targetIdx != len2) {
            return {};
        }

        return result;
    
    }
};