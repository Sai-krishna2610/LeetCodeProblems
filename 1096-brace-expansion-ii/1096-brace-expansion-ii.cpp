class Solution {
public:
    set<string> unite(set<string>& a, set<string>& b) {
        set<string> result = a;
        
        for (string s : b) {
            result.insert(s);
        }
        
        return result;
    }

    set<string> multiply(set<string>& a, set<string>& b) {
        set<string> result;
        
        for (string x : a) {
            for (string y : b) {
                result.insert(x + y);
            }
        }
        
        return result;
    }

    set<string> solve(string& expression, int& i) {
        set<string> result;
        set<string> current = {""};

        while (i < expression.size() && expression[i] != '}') {

            if (expression[i] == ',') {
                // Union current expression with previous expressions
                result = unite(result, current);
                current = {""};
                i++;
            }
            else {
                set<string> part;

                if (expression[i] == '{') {
                    i++; // skip '{'
                    part = solve(expression, i);
                    i++; // skip '}'
                }
                else {
                    part.insert(string(1, expression[i]));
                    i++;
                }

                // Concatenation
                current = multiply(current, part);
            }
        }

        // Add the last expression
        result = unite(result, current);

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};