class Solution {
public:
    int countDigits(int num) {
        
        int original = num;
        int ans = 0;

        while ( num > 0)
        {
            int digit = num % 10;
             
            if (original % digit == 0)
            {
                ans++;
            }

            num = num/10;
        }
        return ans;
    }
};