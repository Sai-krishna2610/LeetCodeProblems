#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)
            return 0;
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);

        vector<bool> visited(n, false);
        visited[0] = true;

        int steps = 0;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                int i = q.front();
                q.pop();
                if(i == n - 1)
                    return steps;

                vector<int> neighbors;
                if(i + 1 < n)
                    neighbors.push_back(i + 1);
                if(i - 1 >= 0)
                    neighbors.push_back(i - 1);
                for(auto idx : mp[arr[i]]) {
                    neighbors.push_back(idx);
                }

                for(auto nei : neighbors) {

                    if(!visited[nei]) {
                        visited[nei] = true;
                        q.push(nei);
                    }
                }
                mp[arr[i]].clear();
            }
            steps++;
        }
        return -1;
    }
};