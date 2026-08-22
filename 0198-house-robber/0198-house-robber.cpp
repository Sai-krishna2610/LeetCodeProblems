class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 0)
            return 0;

        if (n == 1)
            return nums[0];

        int maxRobbedTwoHousesBefore = nums[0];
        int maxRobbedPreviousHouse = max(nums[0], nums[1]);

        for (int currentHouse = 2; currentHouse < n; currentHouse++) {
            int currentMaxRobbed = max(
                nums[currentHouse] + maxRobbedTwoHousesBefore,
                maxRobbedPreviousHouse
            );

            maxRobbedTwoHousesBefore = maxRobbedPreviousHouse;
            maxRobbedPreviousHouse = currentMaxRobbed;
        }

        return maxRobbedPreviousHouse;
    }
};