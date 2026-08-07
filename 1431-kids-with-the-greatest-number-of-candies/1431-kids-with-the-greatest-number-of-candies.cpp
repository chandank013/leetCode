class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

        int maxCandy = 0;

        for ( int i = 0; i < candies.size(); i++)
        {
            if (candies[i] > maxCandy)
                maxCandy = candies[i];
        }

        vector<bool> ans;

        for (int i = 0; i < candies.size(); i++)
        {
            if(candies[i] + extraCandies >= maxCandy)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};