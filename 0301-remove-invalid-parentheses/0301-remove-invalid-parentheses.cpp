class Solution {
public:
    vector<string>ans;

    bool isValid(string s)
    {
        int balance=0;
        for(char c:s)
        {
            if(c=='(')
            {
                balance++;
            }
            else if (c==')')
            {
                balance--;
                if(balance<0)
                {
                    return false;
                }
            }
            
        }
        return balance==0;
    }
    
    void solve(string s, int index, int leftRemove, int rightRemove) {
        if (leftRemove == 0 && rightRemove == 0) {
            if (isValid(s)) {
                ans.push_back(s);
            }
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (i > index && s[i] == s[i - 1])
                continue;

            if (s[i] != '(' && s[i] != ')')
                continue;

            string next = s.substr(0, i) + s.substr(i + 1);

            if (s[i] == '(' && leftRemove > 0) {
                solve(next, i, leftRemove - 1, rightRemove);
            }

            if (s[i] == ')' && rightRemove > 0) {
                solve(next, i, leftRemove, rightRemove - 1);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int leftRemove=0;
        int rightRemove=0;

        for(char c:s)
        {
            if(c=='(')
            {
                leftRemove++;
            }
            else if(c==')')
            {
                if(leftRemove>0)
                {
                    leftRemove--;
                }
                else
                {
                    rightRemove++;
                }
            }
        }
        solve(s,0,leftRemove,rightRemove);
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};