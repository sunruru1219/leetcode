class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        int i = 0;
        while (i < n && s[i] == 'a') i++;
        if (i == n) return true;
        while (i < n && s[i] == 'b') i++;
        if (i == n) return true;
        return false;
    }
};