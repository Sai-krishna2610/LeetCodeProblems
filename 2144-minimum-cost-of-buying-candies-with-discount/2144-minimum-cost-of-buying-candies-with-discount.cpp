class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int skipIndex=0;
        int totalCost=0;
        for(int i=cost.size()-1;i>=0;i--)
        {
            if(skipIndex==2)
            {
                skipIndex=0;
            }
            else
            {
                totalCost+=cost[i];
                skipIndex++;
            }
        }
        return totalCost;
    }
};