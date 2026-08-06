class Solution {
public:
    bool checkPerfectNumber(int num) {
        
        if ( num == 1)
            return false;

        int ans = 0;

        for ( int i = 1; i < num; i++)
        {
            if (num % i == 0)
            {
                ans += i;
            }
        }
        if ( ans == num)
                return true;
            else
                return false;
    }
};