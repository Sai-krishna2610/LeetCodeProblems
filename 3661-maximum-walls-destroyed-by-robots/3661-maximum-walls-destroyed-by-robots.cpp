
class Solution {
public:
    int countWalls(const vector<int>& walls, long long l, long long r) {
        if (l > r) return 0;

        auto left = lower_bound(walls.begin(), walls.end(), (int)l);
        auto right = upper_bound(walls.begin(), walls.end(), (int)r);

        return distance(left, right);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        if (n == 0) return 0;

        sort(walls.begin(), walls.end());

        vector<pair<long long, int>> robotsData;
        for (int i = 0; i < n; i++) {
            robotsData.push_back({robots[i], distance[i]});
        }

        sort(robotsData.begin(), robotsData.end());

        vector<vector<int>> dp(n, vector<int>(2, 0));

        long long INF = 2e18;

        long long pos = robotsData[0].first;
        int dist = robotsData[0].second;

        long long nextPos = (n > 1) ? robotsData[1].first : INF;

        dp[0][0] = countWalls(walls, pos - dist, pos);
        dp[0][1] = countWalls(walls, pos, min(pos + dist, nextPos - 1));

        for (int i = 1; i < n; i++) {
            long long curPos = robotsData[i].first;
            int curDist = robotsData[i].second;

            long long prevPos = robotsData[i - 1].first;
            int prevDist = robotsData[i - 1].second;

            long long nextPos = (i + 1 < n) ? robotsData[i + 1].first : INF;

            int rightGain = countWalls(
                walls,
                curPos,
                min(curPos + curDist, nextPos - 1)
            );

            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + rightGain;

            long long leftStart = max(curPos - curDist, prevPos + 1);
            int leftGain = countWalls(walls, leftStart, curPos);

            dp[i][0] = dp[i - 1][0] + leftGain;

            long long overlapL = leftStart;
            long long overlapR = min(prevPos + (long long)prevDist, curPos - 1);

            int overlapWalls = countWalls(walls, overlapL, overlapR);

            dp[i][0] = max(
                dp[i][0],
                dp[i - 1][1] + leftGain - overlapWalls
            );
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};