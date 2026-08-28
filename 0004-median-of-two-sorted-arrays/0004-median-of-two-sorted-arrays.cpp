class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> arr;

        // Put nums1 into arr
        for (int i = 0; i < nums1.size(); i++)
        {
            arr.push_back(nums1[i]);
        }

        // Put nums2 into arr
        for (int i = 0; i < nums2.size(); i++)
        {
            arr.push_back(nums2[i]);
        }

        // Sort
        sort(arr.begin(), arr.end());

        int n = arr.size();

        // Odd
        if (n % 2 != 0)
        {
            return arr[n / 2];
        }

        // Even
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
};