class Solution {
public:
    int findPos(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, mid;
        int ans = nums.size();
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (mid != nums.size() - 1) {
                if (nums[mid] < target && nums[mid + 1] > target) {
                    return mid + 1;
                }
                else
                {
                    if (nums[mid] < target) {
                    end = mid - 1;
                } else {
                    ans=mid+1;
                    start = mid + 1;
                }
                }
            } else {
                if (nums[mid] < target) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
        return ans;
    }

    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, mid;
        int ans = -1;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                ans = mid;
                return ans;
            } else if (nums[mid] > target) {
                ans=mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        if (ans == -1) {
            return findPos(nums, target);
        } else {
            return ans;
        }
    }
};