class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {

        vector<int> count(1001, 0);

        // Count frequency of every card
        for (int card : deck)
        {
            count[card]++;
        }

        int g = 0;

        // Find GCD of all frequencies
        for (int i = 0; i < count.size(); i++)
        {
            if (count[i] > 0)
            {
                g = gcd(g, count[i]);
            }
        }

        return g >= 2;
    }
};