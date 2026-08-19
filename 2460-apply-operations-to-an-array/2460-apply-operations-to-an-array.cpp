class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {

        // Step 1: Apply operations
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                nums[i] = nums[i] * 2;
                nums[i + 1] = 0;
            }
        }

        // Step 2: Move non-zero elements
        // to the front
        vector<int> ans;

        for (int num : nums)
        {
            if (num != 0)
            {
                ans.push_back(num);
            }
        }

        // Step 3: Add zeroes at the end
        while (ans.size() < nums.size())
        {
            ans.push_back(0);
        }

        return ans;
    }
};