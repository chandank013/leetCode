class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();

        if (n == 0)
            return 0;
        
        vector<int> leftMax;
        vector<int> rightMax;

        int mx = 0;

        for(int i = 0; i < n; i++)
        {
            mx = max(mx, height[i]);
            leftMax.push_back(mx);
        }

        mx = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            mx = max(mx, height[i]);
            rightMax.push_back(mx);
        }

        reverse(rightMax.begin(), rightMax.end());

        int water = 0;
        
        // Calculate trapped water
        for (int i = 0; i < n; i++)
        {
            int level = min(leftMax[i], rightMax[i]);

            water += level - height[i];
        }

        return water;

    }
};