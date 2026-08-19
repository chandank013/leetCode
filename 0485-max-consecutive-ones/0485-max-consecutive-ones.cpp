class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int sum = 0;
        vector<int> ans;

        for ( int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                sum += 1;
            }
            else
            {
                ans.push_back(sum);
                sum = 0;
            }
        }
         // Store the last sequence of 1s
        ans.push_back(sum);
        
        return *max_element(ans.begin(), ans.end());
    }
};