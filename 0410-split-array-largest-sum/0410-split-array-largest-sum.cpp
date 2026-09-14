class Solution {
public:

    bool isPossible(vector<int>& nums, int k, long long maxSum) {

        long long currentSum = 0;
        int parts = 1;

        for (int num : nums) {

            if (currentSum + num > maxSum) {
                parts++;
                currentSum = num;
            }
            else {
                currentSum += num;
            }
        }

        return parts <= k;
    }

    int splitArray(vector<int>& nums, int k) {

        long long low = 0;
        long long high = 0;

        for (int num : nums) {
            low = max(low, (long long)num);
            high += num;
        }

        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (isPossible(nums, k, mid)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};