class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result="";
        for(int i=0;i<words.size();i++)
        {
            int index=0;
            for(int j=0;j<words[i].size();j++)
            {
                index+=weights[words[i][j]-'a'];
            }
            int rem=index%26;
            result.push_back('z'-rem);
        }
        return result;
    }
};