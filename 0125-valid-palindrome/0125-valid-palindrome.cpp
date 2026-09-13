class Solution {
public:
    bool isPalindrome(string s) {
        int leftIndex=0,rightIndex=s.size()-1;
        while(leftIndex<rightIndex)
        {
            while(leftIndex<rightIndex && !isalnum(s[leftIndex]))
            {
                leftIndex++;
            }
            while(leftIndex<rightIndex && !isalnum(s[rightIndex]))
            {
                rightIndex--;
            }
            if(toupper(s[leftIndex])!=toupper(s[rightIndex]))
            {
                return false;
            }
            leftIndex++;
            rightIndex--;
        }
        return true;
    }
};