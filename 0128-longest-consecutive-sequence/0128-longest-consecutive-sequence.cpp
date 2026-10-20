class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int ans = 0;
        for (int x : s) {
            if (!s.count(x - 1)) {
                int n = 1;
                //int curr = x;
                while (s.count(x + 1)) {
                    n++;
                    x++;//curr++;
                }
                ans = max(ans, n);
            }
        }
        return ans;
    }
};