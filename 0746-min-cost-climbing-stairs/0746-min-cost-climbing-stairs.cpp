#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //using recursion
    int ways(int n, vector<int>& cost) {
        if (n <= 1) 
        return 0;
        return min(cost[n - 1] + ways(n - 1, cost),cost[n - 2] + ways(n - 2, cost));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return ways(n, cost);
    }
};
