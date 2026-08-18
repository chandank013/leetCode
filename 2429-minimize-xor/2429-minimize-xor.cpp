class Solution {
public:
    int minimizeXor(int num1, int num2) {

        int count = __builtin_popcount(num2);
        int ans = 0;

        // First take set bits from num1,
        // starting from the highest bit
        for (int i = 31; i >= 0 && count > 0; i--)
        {
            if (num1 & (1 << i))
            {
                ans |= (1 << i);
                count--;
            }
        }

        // If we still need more 1s,
        // take the lowest available bits
        for (int i = 0; i < 32 && count > 0; i++)
        {
            if (!(ans & (1 << i)))
            {
                ans |= (1 << i);
                count--;
            }
        }

        return ans;
    }
};