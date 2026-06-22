class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        {
            return false;
        }

        int original = x;
        long long reverse=0;

        while(x>0){
            int r = x%10;
            x = x/10;
            reverse = reverse*10 + r;
        }

        return original == reverse;
        
    }
};