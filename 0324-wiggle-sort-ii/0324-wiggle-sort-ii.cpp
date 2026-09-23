class Solution {
public:
    void wiggleSort(vector<int>& nums) {

        vector<int> temp = nums;

        sort(temp.begin(), temp.end());

        int n = nums.size();

        int mid = (n + 1) / 2;
        int large = n;

        // Fill even positions with smaller half
        for (int i = 0; i < n; i += 2) {
            nums[i] = temp[--mid];
        }

        // Fill odd positions with larger half
        for (int i = 1; i < n; i += 2) {
            nums[i] = temp[--large];
        }
    }
};