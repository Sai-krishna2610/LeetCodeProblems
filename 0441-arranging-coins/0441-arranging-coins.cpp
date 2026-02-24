class Solution {
public:
    int arrangeCoins(int n) {
        int count=0;
        int i=n;
        int j=1;
        while(i>0)
        {
            i-=j;
            j++;
            if(i>=0)
            {
                count++;
            }
        }
        return count;
    }
};