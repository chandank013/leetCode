class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        vector<int> sIndex(256, -1);
        vector<int> tIndex(256, -1);

        for ( int i = 0; i < s.size(); i++)
        {
            if(sIndex[s[i]] != tIndex[t[i]])
            {
                return false;
            }

            sIndex[s[i]] = i;
            tIndex[t[i]] = i;
        }
        return true;
    }
};