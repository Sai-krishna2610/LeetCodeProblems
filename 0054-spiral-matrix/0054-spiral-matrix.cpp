class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans(matrix.size() * matrix[0].size(), 0);

        int top = 0, left = 0;
        int bottom = matrix.size() - 1;
        int right = matrix[0].size() - 1;
        int index = 0;

        while (top <= bottom && left <= right) {

            int i = left;
            while (i <= right) {
                ans[index++] = matrix[top][i++];
            }
            top++;

            i = top;
            while (i <= bottom) {
                ans[index++] = matrix[i++][right];
            }
            right--;

            if (top <= bottom) {
                i = right;
                while (i >= left) {
                    ans[index++] = matrix[bottom][i--];
                }
                bottom--;
            }

            if (left <= right) {
                i = bottom;
                while (i >= top) {
                    ans[index++] = matrix[i--][left];
                }
                left++;
            }
        }

        return ans;
    }
};