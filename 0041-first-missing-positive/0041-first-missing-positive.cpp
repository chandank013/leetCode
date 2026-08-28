class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        vector<int> arr;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                arr.push_back(nums[i]);
        }

        sort(arr.begin(), arr.end());

        int expected = 1;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] < expected)
            {
                continue;
            }

            if (arr[i] == expected)
            {
                expected++;
            }
            else
            {
                return expected;
            }
        }

        return expected;
    }
};