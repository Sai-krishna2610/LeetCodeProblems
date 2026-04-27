class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> arr(51, 0);   
        for (auto &r : ranges) {
            for (int i = r[0]; i <= r[1]; i++) {
                arr[i] = 1;    
            }
        }

        for (int i = left; i <= right; i++) {
            if (arr[i] == 0)  
                return false;
        }
        
        return true;
    }
};
