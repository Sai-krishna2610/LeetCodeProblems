class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size();
        int n=boxGrid[0].size();

        vector<vector<char>>rotated(n,vector<char>(m));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                rotated[j][m-1-i]=boxGrid[i][j];
            }
        }

        for(int col=0;col<m;col++)
        {
            int empty=n-1;
            for(int row=n-1;row>=0;row--)
            {
                if(rotated[row][col]=='*')
                {
                    empty=row-1;
                }
                else if (rotated[row][col]=='#')
                {
                    rotated[row][col]='.';
                    rotated[empty][col]='#';
                    empty--;
                }
            }
        }
        return rotated;
    }
};