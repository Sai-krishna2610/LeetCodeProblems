class Solution {
public:
    vector<string>ans;
    void Parenthsis(int n,int left,int right,string res)
    {
        if(left+right==2*n)
        {
            ans.push_back(res);
            return ;
        }
        if(left<n)
        {
            Parenthsis(n,left+1,right,res+'(');
        }

        if(right<left)
        {
            Parenthsis(n,left,right+1,res+')');
        }
        
    }
    vector<string> generateParenthesis(int n) {
        int left=0,right=0;
        Parenthsis(n,left,right,"");
        return ans;
    }
};