class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int countEven = 0;

        for ( int i = 0; i < nums.size(); i++)
        {
            int countDigit = 0;
            int num = nums[i];

            while(num > 0)
            {
                num = num / 10;
                countDigit++;
            }

            if(countDigit % 2 == 0)
            {
                countEven++;
            }
        }
        return countEven;
    }
};