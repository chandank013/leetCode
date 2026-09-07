class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        vector<int> freq(128, 0);

        // Mark jewels
        for (int i = 0; i < jewels.size(); i++)
        {
            freq[jewels[i]] = 1;
        }

        int sum = 0;

        // Count stones which are jewels
        for (int i = 0; i < stones.size(); i++)
        {
            if (freq[stones[i]] == 1)
            {
                sum++;
            }
        }

        return sum;
    }
};