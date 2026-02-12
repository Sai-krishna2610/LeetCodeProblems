class Solution {
public:
    int pal(int x)
    {
        long long ans=0;
        while(x>0)
        {
            int rem=x%10;
            x=x/10;
            ans=ans*10+rem;
        }
        if (x>INT_MAX)
        return 0;
        return ans;
    }
    bool isPalindrome(int x) {
        
        if (x<0)
        {
            return 0;
        }
        else if(x==pal(x))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};