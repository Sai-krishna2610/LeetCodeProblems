class Solution {
public:
    bool dfs(vector<int>&arr,int index,vector<bool>&vis)
    {
        int n=arr.size();
        if(index<0|| index>=n ||vis[index])
        {
            return false;
        }
        if(arr[index]==0)
        return true;

        vis[index]=true;
        return dfs(arr,index+arr[index],vis) || dfs(arr,index-arr[index],vis);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool>vis(arr.size(),false);
        return dfs(arr,start,vis);
    }
};