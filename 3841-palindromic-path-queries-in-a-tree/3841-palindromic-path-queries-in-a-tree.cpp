class Solution {
    int LOG;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth;
    int timer = 0;

    class Fenwick {
        vector<int> bit;
        int n;

    public:
        Fenwick(int n) : n(n), bit(n + 2, 0) {}

        void update(int i, int val) {
            for (; i <= n; i += i & -i)
                bit[i] ^= val;
        }

        int query(int i) {
            int ans = 0;
            for (; i > 0; i -= i & -i)
                ans ^= bit[i];
            return ans;
        }

        void rangeUpdate(int l, int r, int val) {
            update(l, val);
            update(r + 1, val);
        }
    };

    void dfs(int u, int p) {
        tin[u] = ++timer;
        up[0][u] = p;

        for (int v : adj[u]) {
            if (v == p)
                continue;

            depth[v] = depth[u] + 1;
            dfs(v, u);
        }

        tout[u] = timer;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int i = 0; i < LOG; i++) {
            if (diff & (1 << i))
                u = up[i][u];
        }

        if (u == v)
            return u;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[i][u] != up[i][v]) {
                u = up[i][u];
                v = up[i][v];
            }
        }

        return up[0][u];
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        adj.assign(n, {});
        up.assign(LOG, vector<int>(n, 0));
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, 0);

        for (int i = 1; i < LOG; i++) {
            for (int u = 0; u < n; u++) {
                up[i][u] = up[i - 1][up[i - 1][u]];
            }
        }

        Fenwick bit(n);

        vector<int> prefix(n, 0);

        for (int u = 0; u < n; u++) {
            int p = up[0][u];

            if (u == 0)
                prefix[u] = 1 << (s[u] - 'a');
            else
                prefix[u] = prefix[p] ^ (1 << (s[u] - 'a'));
        }

        vector<string> suneravilo = queries;
        vector<bool> ans;

        for (string& q : suneravilo) {
            string op;
            int u, v;
            char c;

            stringstream ss(q);
            ss >> op >> u;

            if (op == "update") {
                ss >> c;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');
                int delta = oldMask ^ newMask;

                bit.rangeUpdate(tin[u], tout[u], delta);
                s[u] = c;
            } 
            else {
                ss >> v;

                int maskU = prefix[u] ^ bit.query(tin[u]);
                int maskV = prefix[v] ^ bit.query(tin[v]);

                int w = lca(u, v);
                int mask = maskU ^ maskV ^ (1 << (s[w] - 'a'));

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};