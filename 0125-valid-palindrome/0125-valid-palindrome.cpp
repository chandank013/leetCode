class Solution {
public:
    bool isPalindrome(string s) {
        
        vector<char> ans;

        for( int i = 0; i < s.size(); i++)
        {
            if(isalnum(s[i]))
                ans.push_back(tolower(s[i]));
        }
        
        // check pelindrome
        int left = 0;
        int right = ans.size() - 1;

        while(left < right)
        {
            if(ans[left] != ans[right])
            {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};