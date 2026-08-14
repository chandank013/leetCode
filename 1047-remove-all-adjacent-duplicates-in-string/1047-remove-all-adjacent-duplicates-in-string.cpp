class Solution {
public:
    string removeDuplicates(string s) {

        vector<char> ans;

        for (char ch : s)
        {
            if (!ans.empty() && ans.back() == ch)
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(ch);
            }
        }

        return string(ans.begin(), ans.end());
    }
};