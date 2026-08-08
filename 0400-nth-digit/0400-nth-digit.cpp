class Solution {
public:
    int findNthDigit(int n) {
        
        long long digitCount = 1;
        long long count = 9;
        long long start = 1;

        while (n > digitCount * count) {

            n -= digitCount * count;

            digitCount++;
            count *= 10;
            start *= 10;
        }

        long long number = start + (n - 1) / digitCount;

        int digitIndex = (n - 1) % digitCount;

        string s = to_string(number);

        return s[digitIndex] - '0';

    }
};