class Solution {
public:

    bool isPossible(vector<int>& nums, int threshold, int divisor) {

        int sum = 0;

        for (int num : nums) {

            sum += (num + divisor - 1) / divisor;

            if (sum > threshold)
                return false;
        }

        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while (low < high) {

            int mid = low + (high - low) / 2;

            if (isPossible(nums, threshold, mid)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};