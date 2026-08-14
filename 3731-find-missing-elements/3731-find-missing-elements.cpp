class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int min = nums[0];
        int max = nums[0];

        // Find minimum
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < min)
                min = nums[i];
        }

        // Find maximum
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max)
                max = nums[i];
        }

        vector<int> freq(max + 1, 0);

        // Mark existing numbers
        for (int x : nums)
        {
            freq[x] = 1;
        }

        vector<int> ans;

        // Check from minimum to maximum
        for (int i = min; i <= max; i++)
        {
            if (freq[i] == 0)
                ans.push_back(i);
        }

        return ans;
    }
};