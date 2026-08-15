class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        int ans = 0;
        int len = nums.size();
        
        bool nonZero = false;

        for ( int& x : nums)
        {
            nonZero |= x > 0;
            ans ^= x;
        }

        if (ans != 0)
            return len;
        
        if(nonZero)
            return len - 1;

        
        return 0;

    }
};