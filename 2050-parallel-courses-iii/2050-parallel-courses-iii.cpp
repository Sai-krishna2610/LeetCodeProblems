class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>adj[n];
        for(int i=0;i<relations.size();i++)
        {
            //convert them into 0 based indexing
            adj[relations[i][0]-1].push_back(relations[i][1]-1);
        }

        vector<int>InDeg(n,0);
        for(int i=0;i<n;i++ )
        {
            for(int j=0;j<adj[i].size();j++)
            {
                InDeg[adj[i][j]]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(!InDeg[i])
            {
                q.push(i);
            }
        }

        // maximum time to complete previous course
        vector<int>courseTime(n,0);

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int j=0;j<adj[node].size();j++)
            {
                InDeg[adj[node][j]]--;
                if(!InDeg[adj[node][j]])
                {
                    q.push(adj[node][j]);
                }

                //maximum time to complete previous course+present course time
                courseTime[adj[node][j]]=max(courseTime[adj[node][j]], courseTime[node]+time[node]);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,courseTime[i]+time[i]);
        }
    return ans;
    }
};