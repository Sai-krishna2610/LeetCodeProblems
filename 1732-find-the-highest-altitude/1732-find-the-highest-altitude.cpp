class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0;
        int cur=0;
        for(int i=0;i<gain.size();i++)
        {
            cur+=gain[i];
            maxi=max(cur,maxi);
        }
        return maxi;
    }
};