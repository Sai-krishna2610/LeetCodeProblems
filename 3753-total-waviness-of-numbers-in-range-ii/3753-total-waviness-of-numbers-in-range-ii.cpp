class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;
    Node memo[20][11][11][2];
    bool vis[20][11][11][2];

    Node dfs(int pos, int last, int secondLast,
             bool started, bool tight) {

        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && started &&
            vis[pos][last][secondLast][1]) {
            return memo[pos][last][secondLast][1];
        }

        if (!tight && !started &&
            vis[pos][10][10][0]) {
            return memo[pos][10][10][0];
        }

        int limit = tight ? (s[pos] - '0') : 9;

        Node res = {0, 0};

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, 10, 10, false, ntight);

                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
            }
            else if (!started) {
                Node nxt = dfs(pos + 1, d, 10, true, ntight);

                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
            }
            else {
                int add = 0;

                if (secondLast != 10) {
                    if ((last > secondLast && last > d) ||
                        (last < secondLast && last < d))
                        add = 1;
                }

                Node nxt = dfs(pos + 1, d, last, true, ntight);

                res.cnt += nxt.cnt;
                res.wav += nxt.wav + nxt.cnt * add;
            }
        }

        if (!tight) {
            if (started) {
                vis[pos][last][secondLast][1] = true;
                memo[pos][last][secondLast][1] = res;
            } else {
                vis[pos][10][10][0] = true;
                memo[pos][10][10][0] = res;
            }
        }

        return res;
    }

    long long solve(long long x) {
        if (x <= 0) return 0;

        memset(vis, 0, sizeof(vis));

        s = to_string(x);
        return dfs(0, 10, 10, false, true).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};