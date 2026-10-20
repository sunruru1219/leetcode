class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastPos(256, -1);
        int left = 0;
        int ans = 0;

        for (int j = 0; j < s.size(); ++j) {
            char c = s[j];
            if (lastPos[c] >= left)
                left = lastPos[c] + 1;

            ans = max(ans, j - left + 1);
            lastPos[c] = j;
        }
        return ans;
    }
};