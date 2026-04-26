class Solution {
public:
    int m,n;
    vector<vector<bool>>visited;
    bool dfs(vector<vector<char>>&grid,int r,int c,int pr,int pc)
    {
        visited[r][c]=true;
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

        for (auto &d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;
            if (grid[nr][nc] != grid[r][c])
                continue;

            if (!visited[nr][nc]) {
                if (dfs(grid, nr, nc, r, c))
                    return true;
            }
            else if (nr != pr || nc != pc) {
                return true;
            }
        }

        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        visited.assign(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j])
                {
                    if(dfs(grid,i,j,-1,-1))
                        return true;
                }
            }
        }
        return false;
    }
};