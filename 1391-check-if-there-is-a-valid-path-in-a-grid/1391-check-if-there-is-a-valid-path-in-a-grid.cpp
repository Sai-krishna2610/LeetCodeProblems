class Solution {
public:
    vector<vector<vector<int>>> dirs={
        {},
        {{0,-1},{0,1}},
        {{-1,0},{1,0}},
        {{0,-1},{1,0}},
        {{0,1},{1,0}},
        {{0,-1},{-1,0}},
        {{0,1},{-1,0}}
    };
    bool isValid(int fromType, int dx,int dy, int toType)
    {
        for(auto &d:dirs[toType])
        {
            if(d[0]==-dx && d[1]==-dy)
                return true;
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == m-1 && c == n-1)
                return true;

            int type = grid[r][c];

            for (auto &d : dirs[type]) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                    continue;

                if (vis[nr][nc])
                    continue;

                if (isValid(type, d[0], d[1], grid[nr][nc])) {
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }
};