class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_set<int> s;
        for (int i = 0; i < n; ++i) {
            s.clear();
            for (int j = i; j < n; ++j) {
                s.insert(nums[j]);
                int cnt = s.size();
                ans += cnt * cnt;
            }
        }
        return ans;
    }
};