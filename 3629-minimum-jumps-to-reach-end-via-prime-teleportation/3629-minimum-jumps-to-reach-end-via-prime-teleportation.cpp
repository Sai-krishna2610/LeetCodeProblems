class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 0;

        int MAXV = *max_element(nums.begin(), nums.end());

        // Smallest Prime Factor sieve
        vector<int> spf(MAXV + 1);

        for (int i = 0; i <= MAXV; i++) {
            spf[i] = i;
        }

        for (long long i = 2; i * i <= MAXV; i++) {
            if (spf[i] == i) {
                for (long long j = i * i; j <= MAXV; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }

        // bucket[p] = indices where nums[idx] divisible by p
        unordered_map<int, vector<int>> bucket;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            unordered_set<int> factors;

            while (x > 1) {
                factors.insert(spf[x]);
                x /= spf[x];
            }

            for (int p : factors) {
                bucket[p].push_back(i);
            }
        }

        vector<int> dist(n, -1);

        queue<int> q;

        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            int steps = dist[i];

            if (i == n - 1) {
                return steps;
            }

            // Adjacent moves
            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = steps + 1;
                q.push(i + 1);
            }

            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = steps + 1;
                q.push(i - 1);
            }

            // Prime teleportation
            int val = nums[i];

            // check prime
            if (val > 1 && spf[val] == val) {

                for (int nxt : bucket[val]) {

                    if (dist[nxt] == -1) {
                        dist[nxt] = steps + 1;
                        q.push(nxt);
                    }
                }

                bucket[val].clear();
            }
        }

        return -1;
    }
};