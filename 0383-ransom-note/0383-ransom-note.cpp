class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        vector<int> ransom(26, 0);
        vector<int> mag(26, 0);

        for (int i = 0; i < ransomNote.size(); i++) {
            ransom[ransomNote[i] - 'a']++;
        }

        for (int i = 0; i < magazine.size(); i++) {
            mag[magazine[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {

            if (ransom[i] > mag[i])
                return false;
        }

        return true;
    }
};