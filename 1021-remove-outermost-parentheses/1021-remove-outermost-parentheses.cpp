class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string ans;
        int balance = 1;
        
        for (int i = 1; i < n; ++i) {
            if (s[i] == '(') balance++;
            else balance--;

            if (balance == 0) {
                i++;
                balance++;
            }
            else ans += s[i];
        }
        return ans;
    }
};