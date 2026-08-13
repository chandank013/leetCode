class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int ans = nums.size();
        int ele = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            ans = ans ^ i ^ nums[i];
        }
        return ans;
    }
};