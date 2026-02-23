/*
Here one array we are converting into set and then traversing another and if found save ans set
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> result;
        for (int num : nums2) {
            if (st1.count(num)) {
                result.insert(num);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};