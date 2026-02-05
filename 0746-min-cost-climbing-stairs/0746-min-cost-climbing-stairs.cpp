#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//optimized approach
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n <= 1) 
        return 0;
        int prev2 = 0;
        int prev1 = 0;
        for (int i = 2; i <= n; i++) {
            int curr = min(cost[i - 1] + prev1,
                           cost[i - 2] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
