class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        int even = 0;
        int odd = 1;

        while (even < nums.size() && odd < nums.size()) {
            
            if (nums[even] % 2 == 0) {
                even += 2;
            }
            else if (nums[odd] % 2 == 1) {
                odd += 2;
            }
            else {
                swap(nums[even], nums[odd]);
                even += 2;
                odd += 2;
            }
        }

        return nums;
    }
};


// class Solution {
// public:
//     vector<int> sortArrayByParityII(vector<int>& nums) {

//         vector<int> ans(nums.size());

//         int even = 0;
//         int odd = 1;

//         for (int x : nums) {

//             if (x % 2 == 0) {
//                 ans[even] = x;
//                 even += 2;
//             }
//             else {
//                 ans[odd] = x;
//                 odd += 2;
//             }
//         }

//         return ans;
//     }
// };