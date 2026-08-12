class Solution {
public:
    int calculate(string s) {

        stack<int> st;
        st.push(1);

        long long result = 0;
        long long number = 0;
        int sign = 1;

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            // Number
            if (isdigit(ch))
            {
                number = number * 10 + (ch - '0');
            }

            // Plus
            else if (ch == '+')
            {
                result += sign * number;

                number = 0;
                sign = st.top();
            }

            // Minus
            else if (ch == '-')
            {
                result += sign * number;

                number = 0;
                sign = -st.top();
            }

            // Opening bracket
            else if (ch == '(')
            {
                st.push(sign);
            }

            // Closing bracket
            else if (ch == ')')
            {
                result += sign * number;

                number = 0;

                st.pop();

                sign = st.top();
            }
        }

        result += sign * number;

        return (int)result;
    }
};