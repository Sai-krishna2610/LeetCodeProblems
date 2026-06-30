class Solution {
public:
    static const int MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;
    Matrix multiply(Matrix &A, Matrix &B) {
        int sz = A.size();
        Matrix C(sz, vector<long long>(sz));

        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < sz; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < sz; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int sz = base.size();

        Matrix res(sz, vector<long long>(sz));

        for (int i = 0; i < sz; i++)
            res[i][i] = 1;

        while (exp) {
            if (exp & 1)
                res = multiply(res, base);

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    long long solve(Matrix &P, vector<long long> init) {
        int sz = P.size();

        vector<long long> ans(sz);

        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                ans[i] = (ans[i] + P[i][j] * init[j]) % MOD;
            }
        }

        long long res = 0;

        for (auto x : ans)
            res = (res + x) % MOD;

        return res;
    }

    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;
        int sz = 2 * m;

        Matrix T(sz, vector<long long>(sz));

        for (int x = 0; x < m; x++) {

            for (int y = 0; y < x; y++)
                T[m + y][x] = 1;

            for (int y = x + 1; y < m; y++)
                T[y][m + x] = 1;
        }

        Matrix P = power(T, n - 1);

        vector<long long> up(sz), down(sz);

        for (int i = 0; i < m; i++)
            up[i] = 1;

        for (int i = 0; i < m; i++)
            down[m + i] = 1;

        long long ans = solve(P, up);
        ans = (ans + solve(P, down)) % MOD;

        return ans;
    }
};