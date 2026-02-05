class Solution {
public:
    //optimized approach
    int climbStairs(int n) {
        int prev0=1;
        int prev1=0;
        int curr=prev0+prev1;
        for(int i=n-1;i>=0;i--)
        {
            curr=prev0+prev1;
            prev1=prev0;
            prev0=curr;
        }
        return curr;
    }
};