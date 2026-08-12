class Solution {
public:

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long count(long long x, long long a,
                    long long b, long long c) {

        long long ab = lcm(a, b);
        long long ac = lcm(a, c);
        long long bc = lcm(b, c);

        long long abc = lcm(ab, c);

        return x / a
             + x / b
             + x / c
             - x / ab
             - x / ac
             - x / bc
             + x / abc;
    }

    int nthUglyNumber(int n, int a, int b, int c) {

        long long low = 1;
        long long high = 2000000000LL;

        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (count(mid, a, b, c) >= n)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};