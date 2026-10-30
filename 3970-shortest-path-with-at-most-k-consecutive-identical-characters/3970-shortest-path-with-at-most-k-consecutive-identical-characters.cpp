class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));

        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [cost, node, consecutive] = pq.top();
            pq.pop();

            if (cost != dist[node][consecutive]) {
                continue;
            }

            if (node == n - 1) {
                return (int)cost;
            }

            for (auto& [nextNode, weight] : adj[node]) {
                int nextConsecutive;

                if (labels[node] == labels[nextNode]) {
                    nextConsecutive = consecutive + 1;
                } else {
                    nextConsecutive = 1;
                }

                if (nextConsecutive > k) {
                    continue;
                }

                long long newCost = cost + weight;

                if (newCost < dist[nextNode][nextConsecutive]) {
                    dist[nextNode][nextConsecutive] = newCost;

                    pq.push({
                        newCost,
                        nextNode,
                        nextConsecutive
                    });
                }
            }
        }

        return -1;
    }
};