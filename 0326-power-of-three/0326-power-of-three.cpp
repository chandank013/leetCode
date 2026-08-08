class Solution {
public:
    bool isPowerOfThree(int n) {
        
        int original = n;
        int product = 1;

        while(n){

            if ( n % 3 == 0)
                product *= 3;
                n /= 3;
        }

        if ( product == original)
            return true;
        else
            return false;
    }
};