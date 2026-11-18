class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int result = 0;
        int sign = 1;
        int n = s.size();
        int i = 0;
        while (i < n) {
            // skip empty
            while (s[i] == ' ') i++;

            // numbers
            if (0 <= s[i] - '0' && s[i] - '0' <= 9){
                long long x = 0;
                while (i < n && 0 <= s[i] - '0' && s[i] - '0' <= 9) {
                    x = x * 10 + s[i] - '0';
                    i++;
                }
                result += sign * x;
                //cout << result << endl;;
            }
            // +
            else if (s[i] == '+') {
                sign = 1;
                i++;
            }
            // -
            else if (s[i] == '-') {
                sign = -1;
                i++;
            }
            // (
            else if (s[i] == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
                i++;
            }
            // )
            else if (s[i] == ')') {
                sign = st.top();
                st.pop();
                int temp = st.top();
                st.pop();
                result = temp + sign * result;
                i++;
            }
        }
        return result;
    }
};