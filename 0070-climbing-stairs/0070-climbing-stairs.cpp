class Solution {
public:
    //recursive approach
    int climb(int i,int n)
    {
        if(i==n)
        {
            return 1;
        }
        if(i>n)
        {
            return 0;
        }
        return climb(i+1,n)+climb(i+2,n);
    }
    int climbStairs(int n) {
        return climb(0,n);
    }
};