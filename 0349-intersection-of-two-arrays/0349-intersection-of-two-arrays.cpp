class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> s;
        vector<int> ans;

        // Store num21 elements
        for (int num : nums1)
        {
            s.insert(num);
        }

        // Check nums2 elements
        for (int num : nums2)
        {
            if(s.count(num))
            {
                ans.push_back(num);
                s.erase(num);
            }
        }
        return ans;
    }
};