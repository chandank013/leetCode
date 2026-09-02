class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        vector<int> nums2;

        for (int i = 0; i < nums1.size() - 1; i++)
        {
            for (int j = i + 1; j < nums1.size(); j++)
            {
                int rem = nums1[i] - nums1[j];
                nums2.push_back(rem);
            }
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            cout << nums2[i] << " ";
        }

        return true;
    }
};