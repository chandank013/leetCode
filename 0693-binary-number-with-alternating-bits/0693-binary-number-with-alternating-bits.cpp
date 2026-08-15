class Solution {
public:
    bool hasAlternatingBits(int n) {

        vector<int> ans;

        // Convert n to binary
        while (n != 0)
        {
            int bit = n % 2;
            ans.push_back(bit);
            n = n / 2;
        }

        // Check adjacent bits
        for (int i = 0; i < ans.size() - 1; i++)
        {
            if (ans[i] == ans[i + 1])
            {
                return false;
            }
        }

        return true;
    }
};