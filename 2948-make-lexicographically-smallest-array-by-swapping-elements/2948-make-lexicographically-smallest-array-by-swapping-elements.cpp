class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        int n = nums.size();

        vector<int> idx(n);

        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }

        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });

        vector<int> ans(n);

        int i = 0;

        while (i < n) {

            int j = i + 1;

            while (j < n &&
                   nums[idx[j]] - nums[idx[j - 1]] <= limit) {
                j++;
            }

            vector<int> temp(idx.begin() + i, idx.begin() + j);

            sort(temp.begin(), temp.end());

            for (int k = i; k < j; k++) {
                ans[temp[k - i]] = nums[idx[k]];
            }

            i = j;
        }

        return ans;
    }
};