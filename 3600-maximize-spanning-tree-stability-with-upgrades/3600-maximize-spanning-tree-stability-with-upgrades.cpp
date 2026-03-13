class Solution {
public:

    class UnionFind {
    public:
        vector<int> parent, height;
        int count;

        UnionFind(int n) {
            parent.resize(n);
            height.assign(n, 0);
            count = n;

            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int findRoot(int x) {
            if (parent[x] == x) return x;
            return parent[x] = findRoot(parent[x]);
        }

        bool connect(int a, int b) {
            int pa = findRoot(a);
            int pb = findRoot(b);

            if (pa == pb) return false;

            if (height[pa] < height[pb]) {
                swap(pa, pb);
            }

            parent[pb] = pa;

            if (height[pa] == height[pb]) {
                height[pa]++;
            }

            count--;
            return true;
        }
    };

    bool canBuild(int n, vector<vector<int>>& edges, int k, int target) {

        UnionFind uf(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];

            if (must == 1) {
                if (s < target) return false;
                if (!uf.connect(u, v)) return false;
            }
        }

        for (auto &e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];

            if (must == 0 && s >= target) {
                uf.connect(u, v);
            }
        }

        int used = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];

            if (must == 0 && s < target && s * 2 >= target) {
                if (uf.connect(u, v)) {
                    used++;
                    if (used > k) return false;
                }
            }
        }

        return uf.count == 1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        {
            UnionFind uf(n);

            for (auto &e : edges) {
                if (e[3] == 1) {
                    if (!uf.connect(e[0], e[1])) {
                        return -1;
                    }
                }
            }
        }

        int low = 1, high = 200000;
        int answer = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canBuild(n, edges, k, mid)) {
                answer = mid;
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }

        return answer;
    }
};