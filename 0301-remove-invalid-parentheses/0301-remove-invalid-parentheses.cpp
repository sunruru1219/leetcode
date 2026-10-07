class Solution {
public:
    unordered_set<string> ans;
    int removal;
    
    void remove(int i, int rm, int balance, string& s, string& subs) {
        if (i == s.size()) {
            if (rm == removal && balance == 0)
                ans.insert(subs);
            return;
        }
        
        // delete s[i]
        if ((s[i] == '(' || s[i] ==')') && rm < removal) {
            remove(i + 1, rm + 1, balance, s, subs);
        }

        // keep s[i]
        subs += s[i];
        if (s[i] == '(') balance++;
        else if (s[i] == ')') balance--;

        if (balance >= 0) remove(i + 1, rm, balance, s, subs);
        subs.pop_back();
    }
    vector<string> removeInvalidParentheses(string s) {
        int balance = 0;
        removal = 0;

        for (char c : s) {
            if (c == '(') balance++;
            else if (c == ')') balance--;

            if (balance < 0) {
                removal++;
                balance++;
            }
        }
        removal += balance;

        string subs;
        remove(0, 0, 0, s, subs);

        return vector<string>(ans.begin(), ans.end());
    }
};