class Solution {
public:
    bool isSameAfterReversals(int num) {
        
        int original = num;
        int reversed1 = 0;

        while (num > 0)
        {
            int rem1 = num % 10;
            reversed1 = reversed1*10 + rem1;
            num = num / 10;
        }

        int reversed2 = 0;

        while (reversed1 > 0)
        {
            int rem2 = reversed1 % 10;
            reversed2 = reversed2*10 + rem2;
            reversed1 = reversed1 / 10;
        }

        if (reversed2 == original)
            return true;
        else 
            return false;
    }
};