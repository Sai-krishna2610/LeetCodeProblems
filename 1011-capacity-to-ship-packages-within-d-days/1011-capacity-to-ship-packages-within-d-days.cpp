class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
      if(days>weights.size())
          return -1;
      int start=0;
        int end=0;
        for(int i=0;i<weights.size();i++)
        {
            start=max(start,weights[i]);
            end+=weights[i];
        }
                      int ans=0;
        while(start<=end)    
       {
             int mid=start+(end-start)/2;
             int sum=0;
             int daysCount=1;
             for(int i=0;i<weights.size();i++)
             {
                 sum+=weights[i];
                 if(sum>mid)
                 {
                     sum=weights[i];
                     daysCount++;
                 }
             }
             if(daysCount>days)
             {
                 start=mid+1;
             }
           else
           {
               ans=mid;
               end=mid-1;
           }
       }
       return ans;
           
           
    }
};