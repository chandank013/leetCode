class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        unsigned int xorValue = 0;

        // XOR all numbers
        for (int num : nums)
        {
            xorValue ^= (unsigned int)num;
        }

        // Find rightmost set bit
        unsigned int bit = xorValue & (~xorValue + 1);

        unsigned int a = 0;
        unsigned int b = 0;

        // Divide numbers into two groups
        for (int num : nums)
        {
            if ((unsigned int)num & bit)
            {
                a ^= (unsigned int)num;
            }
            else
            {
                b ^= (unsigned int)num;
            }
        }

        return {(int)a, (int)b};
    }
};