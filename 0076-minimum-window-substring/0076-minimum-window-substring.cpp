class Solution {
public:
    string minWindow(string s, string t) {
       int total=t.size();
       vector<int>m(256,0);
       for(int i=0;i<t.size();i++)
       {
        m[t[i]]++;
       } 
       int start=0,end=0,ans=INT_MAX,index=-1;
       while(end<s.size())
       {
        m[s[end]]--;//decrease the count of char
        if(m[s[end]]>=0)//if count is not -ve
        total--;//decrease the total

        //can we decrease the size of window
        while(!total && start<=end)
        {
            //update the length of substring
            if(ans>end-start+1)
            {
                ans=end-start+1;
                index=start;
            }
            m[s[start]]++;
            if(m[s[start]]>0)
            total++;

            start++;
        }
        end++;
       }
       if(index==-1)
       return "";

       string str="";
       for(int i=index;i<index+ans;i++)
       {
        str+=s[i];
       }
       return str;
    }
};