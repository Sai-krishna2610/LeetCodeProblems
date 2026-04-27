class Solution {
public:
    int calSum(int n)
    {
        return n*(n+1)/2;
    }
    int pivotInteger(int n) {
        int total=calSum(n);
        int curSum=0;
        for(int i=1;i<=n;i++)
        {
            curSum+=i;
            if(total-curSum+i==curSum)
            {
                return i;
            }
        }
        return -1;
    }
};