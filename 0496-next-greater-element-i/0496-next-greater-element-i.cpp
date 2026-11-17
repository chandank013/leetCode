
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1,
                                   vector<int>& nums2) {
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {

            int nge = -1;
            int j = 0;

            // Find nums1[i] in nums2
            while (j < nums2.size() && nums2[j] != nums1[i]) {
                j++;
            }

            // Find next greater element
            for (int k = j + 1; k < nums2.size(); k++) {
                if (nums2[k] > nums1[i]) {
                    nge = nums2[k];
                    break;
                }
            }

            ans.push_back(nge);
        }

        return ans;
    }
};
