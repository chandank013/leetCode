class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        int original = n;
        long long product = 1;

        while(n){

            if ( n % 2 == 0)
                product *= 2;
                n /= 2;
        }

        if ( product == original)
            return true;
        else
            return false;
    }
};