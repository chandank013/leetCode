class Solution {
public:
    int reverse(int x) {
        
        long long reverse = 0;

        while(x != 0)
        {
            int rem = x % 10;
            
            if (reverse > INT_MAX / 10 || (reverse == INT_MAX/10 && rem > 7))
                return 0;
            if (reverse < INT_MIN / 10 || (reverse == INT_MIN/10 && rem < -8))
                return 0;

            reverse = reverse*10 + rem;
            x = x / 10;
        }
        return reverse;
    }
};