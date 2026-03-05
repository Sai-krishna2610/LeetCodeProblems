class Solution {
public:
    int minOperations(string s) {
        int startWith0 = 0;
        int startWith1 = 0;

        for(int i = 0; i < s.length(); i++) {
            char expected0 = (i % 2 == 0) ? '0' : '1';
            if(s[i] != expected0) startWith0++;
            char expected1 = (i % 2 == 0) ? '1' : '0';
            if(s[i] != expected1) startWith1++;
        }
        return min(startWith0, startWith1);
    }
};