class Solution {
public:
    int findComplement(int num) {

        vector<int> binary;

        // Convert number to binary
        while (num != 0)
        {
            int bit = num % 2;
            binary.push_back(bit);

            num = num / 2;
        }

        // Flip every bit
        for (int i = 0; i < binary.size(); i++)
        {
            if (binary[i] == 0)
                binary[i] = 1;
            else
                binary[i] = 0;
        }

        // Convert binary back to decimal
        int ans = 0;
        long long power = 1;

        for (int i = 0; i < binary.size(); i++)
        {
            ans = ans + binary[i] * power;
            power = power * 2;
        }

        return ans;
    }
};


// class Solution {
// public:
//     int findComplement(int num) {

//         int mask = 0;
//         int temp = num;

//         while (temp != 0)
//         {
//             mask = (mask << 1) | 1;
//             temp = temp >> 1;
//         }

//         return num ^ mask;
//     }
// };