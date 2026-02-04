class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int i = 1;
        vector<vector<int>> ans(n, vector<int>(n, 1));
        while(i<=n*n)
        {
            for(int j=left;j<=right;j++)
            {
                // cout<<j<<left<<right<<endl;
                ans[top][j]=i;
                i++;
            }
            top++;
            for(int j=top;j<=bottom;j++)
            {
                ans[j][right]=i;
                i++;
            }
            right--;
            for(int j=right;j>=left;j--)
            {
                ans[bottom][j]=i;
                i++;
            }
            bottom--;
            for(int j=bottom;j>=top;j--)
            {
                ans[j][left]=i;
                i++;
            }
            left++;
        }
        return ans;
    }
};