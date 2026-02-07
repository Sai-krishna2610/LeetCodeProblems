class Solution {
public:
    int minimumDeletions(string s) {
        int bCount = 0;
        int deletions = 0;

        for (char c : s) {
            if (c == 'a') {
                deletions = min(deletions + 1, bCount);
            } else {
                bCount++;
            }
        }

        return deletions;
    }
};
