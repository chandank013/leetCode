class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        
        int n = bottomLeft.size();
        long long ans = 0;

        for ( int i = 0; i < n; i++)
        {
            for ( int j = i + 1; j < n; j++)
            {
                // find overlap width;
                long long width = min(topRight[i][0], topRight[j][0])
                    - max(bottomLeft[i][0], bottomLeft[j][0]);

                // Find overlap height
                long long height =min(topRight[i][1], topRight[j][1])
                    - max(bottomLeft[i][1], bottomLeft[j][1]);

                if ( width > 0 && height > 0)
                {
                    long long side = min(width, height);

                    long long area = side * side;

                    ans = max (ans, area);
                }
            }
        }
        return ans;
    }
};