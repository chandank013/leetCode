class Solution {
public:
    bool isPowerOfFour(int n) {
        
        int original = n;
        int product = 1;

        while(n){

            if ( n % 4 == 0)
                product *= 4;
                n /= 4;
        }

        if ( product == original)
            return true;
        else
            return false;
    }
};