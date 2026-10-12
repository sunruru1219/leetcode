class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string prefix = strs[0];
        for (int i = 1; i < n; ++i) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() -1); //刪掉prefix的最後一個char
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }
};