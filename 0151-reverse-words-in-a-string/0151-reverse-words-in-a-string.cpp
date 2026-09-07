class Solution {
public:
    string reverseWords(string s) {

        vector<string> v;
        string word = "";

        // Extract words
        for (int i = 0; i < s.size(); i++) {

            if (s[i] != ' ') {
                word += s[i];
            }
            else {
                if (word != "") {
                    v.push_back(word);
                    word = "";
                }
            }
        }

        // Add last word
        if (word != "") {
            v.push_back(word);
        }

        // Reverse order of words
        string ans = "";

        for (int i = v.size() - 1; i >= 0; i--) {

            ans += v[i];

            if (i != 0)
                ans += " ";
        }

        return ans;
    }
};