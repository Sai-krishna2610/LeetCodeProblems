class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int totalValue = 0;
        for (int i = 0; i < n; ++i) {
            int totalSubarraysCount = (i + 1) * (n - i);
            int oddSubarraysCount = (totalSubarraysCount + 1) / 2;
            totalValue += arr[i] * oddSubarraysCount;
        }

        return totalValue;
    }
};