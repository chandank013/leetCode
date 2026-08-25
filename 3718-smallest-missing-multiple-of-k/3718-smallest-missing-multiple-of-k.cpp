class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        int num = k;

        while (true)
        {
            bool found = false;

            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == num)
                {
                    found = true;
                    break;
                }
            }

            if (!found)
                return num;

            num += k;
        }
    }
};