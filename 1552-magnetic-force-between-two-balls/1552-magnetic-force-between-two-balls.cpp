class Solution {
public:

    bool canPlace(const vector<int>& position, int m, int force) {
        int count = 1; // Place the first ball in the first basket
        int lastPos = position[0];

        for (int i = 1; i < position.size(); i++) {
            if (position[i] - lastPos >= force) {
                count++;
                lastPos = position[i];
            }
            if (count >= m) return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int low = 1;
        int high = position.back() - position.front();
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canPlace(position, m, mid)) {
                ans = mid;      // This force is possible, try to increase it
                low = mid + 1;
            } else {
                high = mid - 1; // Force is too large, decrease it
            }
        }
        return ans;
    }
};