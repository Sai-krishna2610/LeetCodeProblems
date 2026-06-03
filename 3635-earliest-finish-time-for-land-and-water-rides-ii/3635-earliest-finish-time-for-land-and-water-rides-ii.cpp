class Solution {
public:
    
    long long solve(vector<int>& firstStart,
                    vector<int>& firstDur,
                    vector<int>& secondStart,
                    vector<int>& secondDur) {
        
        int n = firstStart.size();
        int m = secondStart.size();

        vector<pair<int,int>> rides;

        for (int i = 0; i < m; i++) {
            rides.push_back({secondStart[i], secondDur[i]});
        }

        sort(rides.begin(), rides.end());

        vector<int> starts(m);

        for (int i = 0; i < m; i++) {
            starts[i] = rides[i].first;
        }

        vector<long long> prefixMinDur(m);
        prefixMinDur[0] = rides[0].second;

        for (int i = 1; i < m; i++) {
            prefixMinDur[i] =
                min(prefixMinDur[i - 1],
                    (long long)rides[i].second);
        }

        vector<long long> suffixMinFinish(m);

        suffixMinFinish[m - 1] =
            (long long)rides[m - 1].first +
            rides[m - 1].second;

        for (int i = m - 2; i >= 0; i--) {
            suffixMinFinish[i] =
                min(suffixMinFinish[i + 1],
                    (long long)rides[i].first +
                    rides[i].second);
        }

        long long ans = LLONG_MAX;

        for (int i = 0; i < n; i++) {

            long long finishFirst =
                (long long)firstStart[i] + firstDur[i];

            int pos =
                upper_bound(starts.begin(),
                            starts.end(),
                            finishFirst)
                - starts.begin() - 1;

            // Case 1: second ride already open
            if (pos >= 0) {
                ans = min(ans,
                          finishFirst +
                          prefixMinDur[pos]);
            }

            // Case 2: second ride opens later
            if (pos + 1 < m) {
                ans = min(ans,
                          suffixMinFinish[pos + 1]);
            }
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long ans = LLONG_MAX;

        // Land -> Water
        ans = min(ans,
                  solve(landStartTime,
                        landDuration,
                        waterStartTime,
                        waterDuration));

        // Water -> Land
        ans = min(ans,
                  solve(waterStartTime,
                        waterDuration,
                        landStartTime,
                        landDuration));

        return (int)ans;
    }
};