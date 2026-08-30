class Solution {
public:
    bool isValid(string s) {

        vector<char> v;

        for (int i = 0; i < s.size(); i++) {

            // Opening bracket
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                v.push_back(s[i]);
            }

            // Closing bracket
            else {

                if (v.empty())
                    return false;

                if (s[i] == ')' && v.back() != '(')
                    return false;

                if (s[i] == '}' && v.back() != '{')
                    return false;

                if (s[i] == ']' && v.back() != '[')
                    return false;

                v.pop_back();
            }
        }

        return v.empty();
    }
};