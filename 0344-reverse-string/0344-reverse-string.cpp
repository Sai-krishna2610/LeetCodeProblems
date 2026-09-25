class Solution {
public:
    void reverseString(vector<char>& s) {
    stack<char>st;
	for(int i=0;i<s.size();i++){
		st.push(s[i]);
	}
	int i=0;
	while(!st.empty())//st.empty function returns 1 if stack empty
	//returns 0 when stack contains elements
	
	{
		s[i]=st.top();//returns top element into stack
		i++;
		st.pop();
	}
    }
};