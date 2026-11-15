class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nextSmallestRight(n);// smallest element right side of current ele
        vector<int>nextSmallestLeft(n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                nextSmallestRight[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            nextSmallestRight[st.top()]=n;
            st.pop();
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                nextSmallestLeft[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            nextSmallestLeft[st.top()]=-1;
            st.pop();
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,(nextSmallestRight[i]-nextSmallestLeft[i]-1)*heights[i]);
        }
        return ans;
    }
};