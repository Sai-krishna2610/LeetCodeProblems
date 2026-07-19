class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>freq(26,0);
        for(char c:s)
        {
            freq[c-'a']++;
        }
        vector<int>visitedArray(26,0);
        string answer="";
        for(char c:s)
        {
            freq[c-'a']--;
            if(visitedArray[c-'a'])
            continue;
            while(!answer.empty() && answer.back()>c && freq[answer.back()-'a']>0)
            {
                visitedArray[answer.back()-'a']=0;
                answer.pop_back();
            }
            answer.push_back(c);
            visitedArray[c-'a']=1;
        }
        return answer;
    }
};