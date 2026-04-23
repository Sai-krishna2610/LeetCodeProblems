class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // Replace 0 with -1 to balance the array
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                nums[i] = -1;
            }
        }

        unordered_map<int, int> mp; // Map to store the first occurrence of each prefix sum
        int prefix_sum = 0; // Cumulative sum
        int max_length = 0; // Tracks the maximum length
        mp[0] = -1; // Initialize map for handling subarrays starting from index 0

        for (int i = 0; i < nums.size(); i++) {
            prefix_sum += nums[i]; // Update the prefix sum

            // If the prefix sum is found in the map, calculate the length of the subarray
            if (mp.find(prefix_sum) != mp.end()) {
                max_length = max(max_length, i - mp[prefix_sum]);
            } else {
                // Store the first occurrence of this prefix sum
                mp[prefix_sum] = i;
            }
        }

        return max_length;
    }
};
