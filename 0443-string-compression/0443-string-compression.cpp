class Solution {
public:
    int compress(vector<char>& chars) {
        
        vector<char> ans;

        for ( int i = 0; i < chars.size(); i++)
        {
            char ch = chars[i];
            int count = 0;

            while(i < chars.size() && chars[i] == ch)
            {
                count++;
                i++;
            }

            ans.push_back(ch);

            if (count > 1) {
                string num = to_string(count);

                for (int j = 0; j < num.size(); j++) {
                    ans.push_back(num[j]);
                }
            }

            i--;
        }
        for (int i = 0; i < ans.size(); i++) {
            chars[i] = ans[i];
        }

        return ans.size();

    }
};