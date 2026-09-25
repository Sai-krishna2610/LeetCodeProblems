class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";  // Handle the case if the list is empty
        
        // Find the shortest string in the vector to limit the comparison
        string n = *min_element(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
        
        string prefix = "";
        
        // Iterate through each character of the shortest string
        for (int i = 0; i < n.length(); ++i) {
            for (const string& str : strs) {
                if (str[i] != n[i]) {
                    return prefix;  // Return the prefix up to this point
                }
            }
            prefix += n[i];  // Add the character to the prefix
        }
        
        return prefix;  // If we reach here, the entire shortest string is a common prefix
    }
};