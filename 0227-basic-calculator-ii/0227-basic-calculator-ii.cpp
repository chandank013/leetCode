class Solution {
public:
    int calculate(string s) {

        stack<int> st;

        int number = 0;
        char sign = '+';

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            // Build number
            if (isdigit(ch))
            {
                number = number * 10 + (ch - '0');
            }

            // Process operator
            if ((!isdigit(ch) && ch != ' ') || i == s.length() - 1)
            {
                if (sign == '+')
                {
                    st.push(number);
                }
                else if (sign == '-')
                {
                    st.push(-number);
                }
                else if (sign == '*')
                {
                    int top = st.top();
                    st.pop();

                    st.push(top * number);
                }
                else if (sign == '/')
                {
                    int top = st.top();
                    st.pop();

                    st.push(top / number);
                }

                sign = ch;
                number = 0;
            }
        }

        int answer = 0;

        while (!st.empty())
        {
            answer += st.top();
            st.pop();
        }

        return answer;
    }
};