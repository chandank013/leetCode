class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> freq(26, 0);

        // Count frequency
        for(int i = 0; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
        }

        // Find first unique character
        for(int i = 0; i < s.size(); i++)
        {
            if(freq[s[i] - 'a'] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};