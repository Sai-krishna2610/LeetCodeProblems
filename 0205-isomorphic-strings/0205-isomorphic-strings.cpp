class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for (int i = 0; i < s.length(); i++) {
            char a = s[i];
            char b = t[i];

            if (mp1.count(a)) {
                if (mp1[a] != b) {
                    return false;
                }
            } 
            else {
                if (mp2.count(b)) {
                    return false;
                }

                mp1[a] = b;
                mp2[b] = a;
            }
        }

        return true;
    }
};