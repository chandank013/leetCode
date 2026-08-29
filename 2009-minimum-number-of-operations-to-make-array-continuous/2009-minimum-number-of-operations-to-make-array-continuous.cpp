class Solution {
public:
    int minOperations(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> arr;

        // Remove duplicates
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || nums[i] != nums[i - 1])
            {
                arr.push_back(nums[i]);
            }
        }

        int left = 0;
        int maxKeep = 0;

        for (int right = 0; right < arr.size(); right++)
        {
            while (arr[right] - arr[left] >= n)
            {
                left++;
            }

            int windowSize = right - left + 1;

            maxKeep = max(maxKeep, windowSize);
        }

        return n - maxKeep;
    }
};