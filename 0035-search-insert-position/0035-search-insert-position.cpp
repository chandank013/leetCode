class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int L, H;
        
        L = 0;
        H = nums.size() - 1;

        while(L <= H)
        {
            int mid = L + (H - L)/2;

            if (nums[mid] == target)
            {
                return mid;
            }else if (nums[mid] < target)
            {
                L = mid + 1;
            }else
            {
                H = mid - 1;
            }
        }
        return L;
    }
};