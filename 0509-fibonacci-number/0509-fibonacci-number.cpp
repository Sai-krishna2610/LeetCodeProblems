class Solution {
public:
    //optimized  Approach
    int fib(int n) {
        if (n<=1){
            return n;
        }
        int first=0,second=1;
        int ans;
        for(int i=2;i<=n;i++)
        {
            ans=first+second;
            first=second;
            second=ans;
        }
        return ans;
    }
};