class Solution {
public:
    bool checkString(string s) {
       bool bs=false;
       for(char c:s)
       {
         if(c=='a' && !bs)
         {
            continue;
         }
         if(c=='a' && bs)
         {
            return false;
         }
         if(c=='b')
         {
            bs=true;
         }
       }
       return true; 
    }
};