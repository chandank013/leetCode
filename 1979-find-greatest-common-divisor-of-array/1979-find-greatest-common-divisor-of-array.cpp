class Solution {
public:
    int findGCD(vector<int>& nums) {

        int smallest = nums[0];
        int largest = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            smallest = min(smallest, nums[i]);
            largest = max(largest, nums[i]);
        }

        return gcd(smallest, largest);
    }
};