class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt=0;
        for(string &ptn:patterns){
            if(word.find(ptn)!=string::npos)
            cnt++;
        }
        return cnt;
    }
};