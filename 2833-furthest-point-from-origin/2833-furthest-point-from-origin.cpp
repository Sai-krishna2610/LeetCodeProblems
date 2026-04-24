class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left=0,right=0,mid=0;
        for(char m:moves)
        {
            if(m=='L')
            {
                left++;
            }
            else if(m=='R')
            {
                right++;
            }
            else
            {
                mid++;
            }
        }
        return max(left,right)+mid-min(left,right);
    }
};