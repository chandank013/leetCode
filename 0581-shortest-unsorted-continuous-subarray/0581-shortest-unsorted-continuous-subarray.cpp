class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        vector<int> arr;

        // Copy nums using push_back
        for (int i = 0; i < nums.size(); i++)
        {
            arr.push_back(nums[i]);
        }

        // Sort the copied array
        sort(arr.begin(), arr.end());

        int left = 0;
        int right = nums.size() - 1;

        // Find first different element
        while (left < nums.size() && nums[left] == arr[left])
        {
            left++;
        }

        // Already sorted
        if (left == nums.size())
            return 0;

        // Find last different element
        while (right >= 0 && nums[right] == arr[right])
        {
            right--;
        }

        return right - left + 1;
    }
};