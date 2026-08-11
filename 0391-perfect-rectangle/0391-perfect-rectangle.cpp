class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {

        long long area = 0;

        int minX = INT_MAX;
        int minY = INT_MAX;
        int maxX = INT_MIN;
        int maxY = INT_MIN;

        set<pair<int,int>> corners;

        for (auto &r : rectangles)
        {
            int x1 = r[0];
            int y1 = r[1];
            int x2 = r[2];
            int y2 = r[3];

            // Find outer boundary
            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);

            // Add area
            area += 1LL * (x2 - x1) * (y2 - y1);

            // Four corners
            pair<int,int> c1 = {x1, y1};
            pair<int,int> c2 = {x1, y2};
            pair<int,int> c3 = {x2, y1};
            pair<int,int> c4 = {x2, y2};

            // Toggle corners
            if (!corners.insert(c1).second)
                corners.erase(c1);

            if (!corners.insert(c2).second)
                corners.erase(c2);

            if (!corners.insert(c3).second)
                corners.erase(c3);

            if (!corners.insert(c4).second)
                corners.erase(c4);
        }

        // Area of outer rectangle
        long long bigArea =
            1LL * (maxX - minX) * (maxY - minY);

        // Area must match
        if (area != bigArea)
            return false;

        // Exactly 4 corners should remain
        if (corners.size() != 4)
            return false;

        // They must be the outer 4 corners
        if (!corners.count({minX, minY}))
            return false;

        if (!corners.count({minX, maxY}))
            return false;

        if (!corners.count({maxX, minY}))
            return false;

        if (!corners.count({maxX, maxY}))
            return false;

        return true;
    }
};