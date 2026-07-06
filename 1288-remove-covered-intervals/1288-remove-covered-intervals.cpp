class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[]
        (vector<int>&a,vector<int>&b)
        {
            if (a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0];
        });
        int res=0;
        int maximumEnd=-1;
        for(auto &it:intervals)
        {
            if(it[1]>maximumEnd)
            {
                res++;
                maximumEnd=it[1];
            }
        }
        return res;
    }
};