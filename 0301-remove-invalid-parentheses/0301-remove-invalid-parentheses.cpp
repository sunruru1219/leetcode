class Solution {
public:
    unordered_set<string> ans;
    int removal;
    bool valid(string s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') balance++;
            else if (c == ')') balance--;
            if (balance < 0) return false;
        }
        return balance == 0;
    }
    void remove(int i, int rm, string& s, string subs) {
        if (rm == removal) {
            subs += s.substr(i, s.size() - i);
            if (valid(subs)) ans.insert(subs);
            return;
        }
        if (i == s.size()) {
            if (rm == removal && valid(subs))
                ans.insert(subs);
            return;
        }
        
        if ((s[i] == '(' || s[i] ==')') && rm < removal) {
            remove(i + 1, rm + 1, s, subs);
        }
        remove(i + 1, rm, s, subs + s[i]);
    }
    vector<string> removeInvalidParentheses(string s) {
        int less = 0;
        int balance = 0;
        int letter = 0;
        for (char c : s) {
            if (c == '(') balance++;
            else if (c == ')') balance--;
            else letter++;

            if (balance < 0) {
                less++;
                balance++;
            }
        }
        less += balance;
        removal = less;
        if (removal + letter == s.size()) {
            string temp;
            for (char c : s) {
                if (c != '(' && c != ')') temp += c;
            }
            return {temp};
        }

        remove(0, 0, s, "");

        vector<string> res;
        for (auto str : ans) {
            res.push_back(str);
        }

        return res;
    }
};