class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> words;
        string word;

        // Convert string into words
        for (int i = 0; i <= s.size(); i++) {

            if (i == s.size() || s[i] == ' ') {
                words.push_back(word);
                word = "";
            }
            else {
                word += s[i];
            }
        }

        // Number of pattern characters and words must be same
        if (pattern.size() != words.size())
            return false;

        vector<string> p(26, "");
        vector<char> used(26, false);

        for (int i = 0; i < pattern.size(); i++) {

            int index = pattern[i] - 'a';

            // Pattern character not mapped yet
            if (p[index] == "") {

                // Check whether this word is already mapped
                for (int j = 0; j < 26; j++) {
                    if (p[j] == words[i])
                        return false;
                }

                p[index] = words[i];
            }

            // Pattern character already mapped
            else {

                if (p[index] != words[i])
                    return false;
            }
        }

        return true;
    }
};