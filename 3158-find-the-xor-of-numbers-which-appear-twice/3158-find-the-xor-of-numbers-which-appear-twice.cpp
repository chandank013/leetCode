class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {

        vector<int> freq(51, 0);

        for (int x : nums)
        {
            freq[x]++;
        }

        int ans = 0;

        for (int i = 0; i < freq.size(); i++)
        {
            if (freq[i] == 2)
            {
                ans ^= i;
            }
        }

        return ans;
    }
};