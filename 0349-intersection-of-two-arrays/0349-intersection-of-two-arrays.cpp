/*
The below approach is using binary search
Here first we sort one of the array consider nums2 
then iterate first array then using binarysearch check is it present in nums2 or not 
then if present store that number and return it
Time complexity: O((n + m) log m)

we can optimize 
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        sort(nums2.begin(), nums2.end());
        unordered_set<int> res;

        for (int i = 0; i < nums1.size(); i++) {

            if (binary_search(nums2.begin(), nums2.end(), nums1[i])) {
                res.insert(nums1[i]);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};