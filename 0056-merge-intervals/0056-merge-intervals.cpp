class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;

        // Sort interval from starting points
        sort(intervals.begin(), intervals.end());

        // Transverse the interval
        for(auto interval : intervals)
        {
            // If ans is empty or no overlap
            if (ans.empty() || ans.back()[1] < interval[0])
            {
                ans.push_back(interval);
            }
            else
            {
                // Overlap → merge
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }
        return ans;
    }
};