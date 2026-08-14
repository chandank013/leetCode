class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        vector<int> binary(32);

        // Store 32 bits
        for (int i = 0; i < 32; i++)
        {
            binary[i] = n % 2;
            n = n / 2;
        }

        // Create reversed number
        uint32_t ans = 0;

        for (int i = 0; i < 32; i++)
        {
            ans = ans * 2 + binary[i];
        }

        return ans;
    }
};