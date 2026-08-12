class Solution {
public:
    int smallestRepunitDivByK(int k) {

        // A number ending in 0 or 5 cannot be
        // made only of 1s and be divisible by 2 or 5.
        if (k % 2 == 0 || k % 5 == 0)
            return -1;

        int rem = 0;

        for (int length = 1; length <= k; length++)
        {
            rem = (rem * 10 + 1) % k;

            if (rem == 0)
                return length;
        }

        return -1;
    }
};