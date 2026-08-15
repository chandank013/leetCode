class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int ans = 0;

        int num = x ^ y;

        while(num != 0)
        {
            num = num & (num - 1);
            ans++;
        }
        return ans;
    }
};