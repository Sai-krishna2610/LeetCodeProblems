class Solution {
public:
    int maxDepth(string s) {
        int dep=0,ans=0;
        for(auto c:s)
        {
            if(c=='(')
            {
                dep++;
            }
            else if(c==')')
            {
                dep--;
            }
            ans=max(dep,ans);
        }
        return ans;
    }
};