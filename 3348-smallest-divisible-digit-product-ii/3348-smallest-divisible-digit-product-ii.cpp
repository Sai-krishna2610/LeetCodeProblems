class Solution {
public:
    using ll = long long;

    string constructSuffix(ll target, int slots) {
        string result;

        for (int val = 9; val >= 2; val--) {
            while (target % val == 0) {
                result.push_back(char(val + '0'));
                target /= val;
            }
        }

        while ((int)result.size() < slots) {
            result.push_back('1');
        }

        reverse(result.begin(), result.end());
        return result;
    }

    string smallestNumber(string s, long long target) {
        int len = s.size();

        ll check = target;
        for (int prime : {2, 3, 5, 7}) {
            while (check % prime == 0) {
                check /= prime;
            }
        }

        if (check != 1) {
            return "-1";
        }

        vector<ll> needAfterPrefix(len + 1, target);

        for (int idx = 0; idx < len; idx++) {
            int curDigit = s[idx] - '0';

            if (curDigit == 0) {
                break;
            }

            needAfterPrefix[idx + 1] =
                needAfterPrefix[idx] / gcd(needAfterPrefix[idx], (ll)curDigit);
        }

        if (needAfterPrefix[len] == 1) {
            return s;
        }

        int firstZero = s.find('0');
        int lastPos = (firstZero == string::npos) ? len - 1 : firstZero;

        for (int pos = lastPos; pos >= 0; pos--) {
            ll remaining = needAfterPrefix[pos];
            int remainingSlots = len - pos - 1;

            for (int nextDigit = (s[pos] - '0') + 1; nextDigit <= 9; nextDigit++) {
                ll nextNeed = remaining / gcd(remaining, (ll)nextDigit);

                string suffix = constructSuffix(nextNeed, remainingSlots);

                if ((int)suffix.size() == remainingSlots) {
                    return s.substr(0, pos) + char(nextDigit + '0') + suffix;
                }
            }
        }

        return constructSuffix(target, len + 1);
    }
};