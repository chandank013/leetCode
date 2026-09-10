class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        // last[j] = word1 mein word2[j] ki last possible position
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        // Right to left matching
        while (i >= 0 && j >= 0) {

            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }

            i--;
        }

        vector<int> ans;

        bool changed = false;

        j = 0;

        // Left to right greedy
        for (i = 0; i < n; i++) {

            if (j == m)
                break;

            if (word1[i] == word2[j]) {

                ans.push_back(i);
                j++;
            }

            else if (!changed &&
                     (j == m - 1 || i < last[j + 1])) {

                // Use our one allowed change
                ans.push_back(i);
                changed = true;
                j++;
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};