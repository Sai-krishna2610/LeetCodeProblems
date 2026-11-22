class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {

        vector<int> inDeg(n+1, 0);
        vector<vector<int>> adj(n+1);

        for(int i = 0; i < relations.size(); i++)
        {
            int first = relations[i][0];
            int second = relations[i][1];

            adj[first].push_back(second);
            inDeg[second]++;
        }

        queue<int> q;

        vector<int> dp(n+1, 0);

        for(int i = 1; i <= n; i++)
        {
            if(inDeg[i] == 0)
            {
                q.push(i);
                dp[i] = time[i-1];
            }
        }

        int ans = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            ans = max(ans, dp[node]);

            for(int neighbour : adj[node])
            {
                dp[neighbour] = max(dp[neighbour],
                                    dp[node] + time[neighbour-1]);

                inDeg[neighbour]--;

                if(inDeg[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }

        return ans;
    }
};