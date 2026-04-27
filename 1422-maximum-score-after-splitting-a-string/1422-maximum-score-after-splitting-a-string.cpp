class Solution {
public:
    int maxScore(string s) {
        int count1 = 0;  // Count of 1s in the string
        for (char c : s) {
            if (c == '1') {
                count1++;
            }
        }
    int ans = 0;  // To store the maximum score
    int count0 = 0;  // To count the 0s in the left substring
    // Iterate through the string, except the last character to ensure two non-empty substrings
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == '0') {
            count0++;  // Increment count0 if 0 appears
        } 
        else {
            count1--;  // Decrement count1 if 1 appears
        }
        ans = max(ans, count0 + count1);  // Update the maximum score
    }
    return ans; 
    }
};