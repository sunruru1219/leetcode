class Solution {
public:
    int minChanges(string s) {
        int n = s.size();

        int ans = 0;
        int i = 0;
        while (i < n) {
            if (s[i] != s[i + 1]) ans++;
            i += 2;
        }
        return ans;
    }
};