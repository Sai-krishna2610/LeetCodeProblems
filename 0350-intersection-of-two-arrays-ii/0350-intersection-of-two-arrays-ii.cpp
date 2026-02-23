/*
first get frequency of one array consider nums1
then iterate over nums2 check if freq >0 then save that number in result
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
     unordered_map<int,int> freq;
        vector<int> result;

        for (int num : nums1) {
            freq[num]++;
        }
        for (int num : nums2) {
            if (freq[num] > 0) {
                result.push_back(num);
                freq[num]--;  
            }
        }
        return result;
    }
};