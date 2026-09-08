class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size())
            return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // Count characters of s1
        for (int i = 0; i < s1.size(); i++) {
            freq1[s1[i] - 'a']++;
        }

        int window = s1.size();

        // First window of s2
        for (int i = 0; i < window; i++) {
            freq2[s2[i] - 'a']++;
        }

        if (freq1 == freq2)
            return true;

        // Move window
        for (int i = window; i < s2.size(); i++) {

            // Add new character
            freq2[s2[i] - 'a']++;

            // Remove old character
            freq2[s2[i - window] - 'a']--;

            if (freq1 == freq2)
                return true;
        }

        return false;
    }
};